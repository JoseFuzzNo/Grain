#ifndef GRAIN_H
#define GRAIN_H

#include "window.h"
#include "oscillator.h"

/**
 * Clase que representa un grano en un sintetizador granular
 * @author jose
 */
class Grain : public Oscillator {
private:
    float sampleRate;
    float mul;
    double phase;
    float incr;
    FloatArray buffer;
    float bufferSize;
    float initPoint;
    float grainSize;

public:
    void setFrequency( float freq ) {
        incr = freq * mul;
    }
    Grain( float sr );
    void setBuffer( const FloatArray buffer, float size );
    void setSampleRate( float sr );
    void setSpeed( float speed );
    void setInitPoint( float ip );
    void setGrainSize( float gs );
    void reset( );
    void setPhase( float ph );
    float getNextSample( );
};

#endif // GRAIN_H
