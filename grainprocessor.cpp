#include "grainprocessor.h"

GrainProcessor::GrainProcessor( QtJack::Client& client, QObject *parent ) : QObject( parent ), Processor( client ) {
    // Se configuran entradas y salidas
    inL = client.registerAudioInPort( "in_L" );
    inR = client.registerAudioInPort( "in_R" );
    outL = client.registerAudioOutPort( "out_L" );
    outR = client.registerAudioOutPort( "out_R" );

    // Se reserva memoria para el buffer
    ringBuffer = QtJack::AudioRingBuffer( );

    // Se asocia el puntero al grano
    grainBuffer = Instrument::instance( )->grainBufferPointer( );

    connect( Instrument::instance( ), SIGNAL( soundFileChanged( ) ), this, SLOT( updateSoundFile( ) ) );
    connect( &decoder, SIGNAL( bufferReady( ) ), this, SLOT( transferSamples( ) ) );
    connect( &decoder, SIGNAL( finished( ) ), this, SLOT( decodingFinished( ) ) );
    connect( &decoder, SIGNAL( error( QAudioDecoder::Error ) ), this, SLOT( decodingError( QAudioDecoder::Error ) ) );

    startTimer( 1000 );
}

void GrainProcessor::updateSoundFile( ) {

    // Configuracion decoder
    QAudioFormat targetAudioFormat;
    targetAudioFormat.setSampleRate( _client.sampleRate( ) );
    targetAudioFormat.setSampleType( QAudioFormat::SignedInt );
    targetAudioFormat.setChannelCount( 2 );
    //targetAudioFormat.setCodec( "audio/x-raw" );
    targetAudioFormat.setCodec( "audio/pcm" );
    decoder.setAudioFormat( targetAudioFormat );

    decoder.setSourceFilename( Instrument::instance( )->soundFile( ) );
    decoder.start( );

    // Se vacia el buffer
    grainBuffer->clear( );
}

void GrainProcessor::transferSamples( ) {
    QAudioBuffer buffer;
    buffer = decoder.read( );
    if ( buffer.isValid( ) ) {
        const QAudioBuffer::S16S *stereoBuffer;
        stereoBuffer = buffer.constData<QAudioBuffer::S16S>( );
        for ( int i = 0; i < buffer.frameCount( ); i++ ) {
            grainBuffer->append( static_cast<QtJack::AudioSample>( stereoBuffer[i].left / 65536.0 ) );
        }

    }
}

void GrainProcessor::decodingFinished( ) {
    // Se envia el buffer al instrumento.
    // El decoder se para solo, no hay nada mas que hacer.
    Instrument::instance( )->setGrainBuffer( );
}

void GrainProcessor::decodingError( QAudioDecoder::Error error ) {
    QString msg;
    switch(error) {
        case QAudioDecoder::NoError:
            break;
        case QAudioDecoder::ResourceError:
            msg = "A media resource couldn't be resolved.";
            break;
        case QAudioDecoder::FormatError:
            msg = "The format of a media resource isn't supported.";
            break;
        case QAudioDecoder::AccessDeniedError:
            msg =  "There are not the appropriate permissions to play a media resource.";
            break;
        case QAudioDecoder::ServiceMissingError:
            msg =  "A valid playback service was not found, playback cannot proceed.";
            break;
        default:
            msg =  "Decoding failed with an unknown error.";
            break;
    }
    msg.prepend( "Error: " );
    qDebug( msg.toLatin1( ) );
}

void GrainProcessor::process( int samples ) {

    // TEST
    // Se reproduce el buffer

    double outputVolume = Instrument::instance( )->outputVolume( );
    static int phase = 0;
    QtJack::AudioSample *outputL = static_cast<float*>( outL.buffer( samples ).internalMemory( ) );
    for ( int i = 0; i < samples; i++ ) {
        if ( grainBuffer->size( ) > phase ) {
            outputL[i] = grainBuffer->at( phase ).toFloat( );
            outputL[i] *= outputVolume;
            phase++;
        } else {
            phase = 0;
        }
    }
    Instrument::instance( )->setInitPoint( ( double )phase / (double)grainBuffer->size( ) );
}

void GrainProcessor::timerEvent( QTimerEvent* ) {
    // Se actualizan los valores de estado del servidor
    Instrument::instance( )->setCpuLoad( _client.cpuLoad( ) / 100.0 );


    qDebug() << "[GrainProcessor] "
             << "Samples remaining in the grain buffer: "
             <<  grainBuffer->length( );
}
