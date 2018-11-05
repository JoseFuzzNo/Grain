#include "grainprocessor.h"

GrainProcessor::GrainProcessor( QtJack::Client& client, QObject *parent ) :
    QObject( parent ),
    Processor( client ) {
    // Se configuran entradas y salidas
    inL = client.registerAudioInPort( "in_L" );
    inR = client.registerAudioInPort( "in_R" );
    outL = client.registerAudioOutPort( "out_L" );
    outR = client.registerAudioOutPort( "out_R" );

    // Se reserva memoria para el grano (100 s)
    grainBuffer = AudioBuffer::create( 2, client.sampleRate( ) * 600 );
    // Se asocia el puntero al grano
    Instrument::instance( )->setBuffer( grainBuffer, 1 );


    connect( Instrument::instance( ), SIGNAL( soundFileChanged( ) ), this, SLOT( updateSoundFile( ) ) );
    connect( &decoder, SIGNAL( bufferReady( ) ), this, SLOT( transferSamples( ) ) );
    connect( &decoder, SIGNAL( finished( ) ), this, SLOT( decodingFinished( ) ) );
    connect( &decoder, SIGNAL( error( QAudioDecoder::Error ) ), this, SLOT( decodingError( QAudioDecoder::Error ) ) );

    startTimer( 1000 );

    bufferSize = 0;


    grainL = new Grain( client.sampleRate( ) );
    grainR = new Grain( client.sampleRate( ) );
    grainL->setBuffer( grainBuffer.getSamples( 0 ), bufferSize );
    grainR->setBuffer( grainBuffer.getSamples( 1 ), bufferSize );


}

void GrainProcessor::updateSoundFile( ) {

    // Configuracion decoder
    QAudioFormat targetAudioFormat;
    targetAudioFormat.setSampleRate( _client.sampleRate( ) );
    targetAudioFormat.setSampleType( QAudioFormat::SignedInt );
    targetAudioFormat.setChannelCount( 2 );
    //targetAudioFormat.setCodec( "audio/x-raw" );
    targetAudioFormat.setCodec( "audio/pcm" );

    if ( decoder.state( ) != QAudioDecoder::StoppedState )
        decoder.stop( );
    decoder.setAudioFormat( targetAudioFormat );
    bufferSize = 0;
    decoder.setSourceFilename( Instrument::instance( )->soundFile( ) );
    decoder.start( );


}

void GrainProcessor::transferSamples( ) {
    QAudioBuffer buffer;
    buffer = decoder.read( );
    if ( buffer.isValid( ) ) {
        const QAudioBuffer::S16S *stereoBuffer;
        stereoBuffer = buffer.constData<QAudioBuffer::S16S>( );
        for ( int i = 0; i < buffer.frameCount( ); i++ ) {
            grainBuffer.getSamples( 0 )[bufferSize] =  stereoBuffer[i].left / 65536.0;
            grainBuffer.getSamples( 1 )[bufferSize] =  stereoBuffer[i].right / 65536.0;
            bufferSize++;
        }

    }
}

void GrainProcessor::decodingFinished( ) {
    // Se envia el buffer al instrumento.
    // El decoder se para solo, no hay nada mas que hacer.
    Instrument::instance( )->setBuffer( grainBuffer, bufferSize );
    grainL->setBuffer( grainBuffer.getSamples( 0 ), bufferSize );
    grainR->setBuffer( grainBuffer.getSamples( 1 ), bufferSize );
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

QtJack::AudioPort GrainProcessor::outputL( ) {
    return outL;
}

QtJack::AudioPort GrainProcessor::outputR( ) {
    return outR;
}

void GrainProcessor::process( int samples ) {
    // Punteros a los buffers de salida
    QtJack::AudioSample *outputL = static_cast<float*>( outL.buffer( samples ).internalMemory( ) );
    QtJack::AudioSample *outputR = static_cast<float*>( outR.buffer( samples ).internalMemory( ) );

    // Parametros de control
    Instrument *instrument = Instrument::instance( );
    double tune = instrument->tune( );
    double gain = instrument->gain( );
    double outputVolume = instrument->outputVolume( );
    double initPoint = instrument->initPoint( );
    double grainSize = instrument->grainSize( );



    //Grain
    grainL->setInitPoint( initPoint );
    grainL->setGrainSize( grainSize );
    grainL->setSpeed( pow( 2, tune / 12 ) );
    grainR->setInitPoint( initPoint );
    grainR->setGrainSize( grainSize );
    grainR->setSpeed( pow( 2, tune / 12 ) );
    for ( int i = 0; i < samples; i++ ) {
        outputL[i] = grainL->getNextSample( );
        outputR[i] = grainR->getNextSample( );
    };


    // Volumen de salida
    for ( int i = 0; i < samples; i++ ) {
        outputL[i] *= outputVolume;
        outputR[i] *= outputVolume;
    }
}

void GrainProcessor::timerEvent( QTimerEvent* ) {
    // Se actualizan los valores de estado del servidor
    Instrument::instance( )->setCpuLoad( _client.cpuLoad( ) / 100.0 );


    qDebug() << "[GrainProcessor] "
             << "Samples in the grain buffer: "
             <<  bufferSize << " / " << grainBuffer.getSamples( 0 ).getSize( );
}
