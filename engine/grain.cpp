#include "grain.h"

Grain::Grain( float sr ) {
    phase = 0.0f;
    incr = 0.0f;
    setSampleRate( sr );
}
void Grain::setBuffer( const FloatArray buffer, float size ) {
    this->buffer = buffer;
    bufferSize = size;
}
void Grain::setSampleRate( float sr )  {
    sampleRate = sr;
    mul = 2 * M_PIf32 / sr;
}
void Grain::setSpeed( float speed ) {
    if ( grainSize * bufferSize )
        incr = speed / ( grainSize * bufferSize );
}
void Grain::setInitPoint( float ip ) {
    if ( ip + grainSize > 1 ) {
        initPoint = 1 - grainSize;
    } else if ( ip < 0 ) {
        initPoint = 0;
    } else {
        initPoint = ip;
    }
}
void Grain::setGrainSize( float gs ) {
    // gs vale entre 0 y 1
    if ( initPoint + gs > 1 ) {
        grainSize = 1 - initPoint;
    } else if ( gs < 0 ) {
        grainSize = 0;
    } else {
        grainSize = gs;
    }
}
void Grain::reset( ) {
    phase = 0.0f;
}
void Grain::setPhase( float ph ) {
    phase = ph;
}
float Grain::getNextSample( )  {
    int idx = bufferSize * ( initPoint + ( phase * grainSize ) );
    float sample = buffer[idx];
    sample *= WINDOW[static_cast<int>( WINDOW_SIZE * phase )];
    phase += incr;
    if ( phase >= 1 )
        phase -= 1;
    return sample;
}

