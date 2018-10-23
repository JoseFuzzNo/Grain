#include "grainprocessor.h"

GrainProcessor::GrainProcessor( QtJack::Client& client ) : Processor( client ) {
    // Se configuran entradas y salidas
    inL = client.registerAudioInPort( "in_L" );
    inR = client.registerAudioInPort( "in_R" );
    outL = client.registerAudioOutPort( "out_L" );
    outR = client.registerAudioOutPort( "out_R" );

    // Se reserva memoria para el buffer
    ringBuffer = QtJack::AudioRingBuffer( );
}

void GrainProcessor::process( int samples ) {
    // Una forma de procesar el buffer
    inL.buffer( samples ).push( ringBuffer );
    outL.buffer( samples ).pop( ringBuffer );
    outL.buffer( samples ).multiply( Instrument::instance( )->outputVolume( ) );

    // Otra forma con control sobre las muestras individuales
    QtJack::AudioSample *inputR = ( float* ) inR.buffer( samples ).internalMemory( );
    QtJack::AudioSample *outputR = ( float* ) outR.buffer( samples ).internalMemory( );
    for ( int i = 0; i < samples; i++ ) {
        outputR[i] = inputR[i] * Instrument::instance( )->outputVolume( );
    }

    // Se actualizan los valores de estado del servidor
    Instrument::instance( )->setCpuLoad( _client.cpuLoad( ) / 100.0 );
}
