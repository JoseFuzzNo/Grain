#ifndef GRAINOSCILLATOR_H
#define GRAINOSCILLATOR_H

#include "grain.h"
#include <QtMath>

template<int GRAINS>
class GrainOscillator : public Oscillator {
private:
    Grain *grains[GRAINS];
protected:
    void setFrequency( float freq ) {
        for ( int i = 0; i < GRAINS; i++ )
            grains[i]->setFrequency( freq );
    }
public:
    GrainOscillator( float sr ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i] = new Grain( sr );
        }
    }
    void setBuffer( const FloatArray buffer, float size ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i]->setBuffer( buffer, size );
            grains[i]->setPhase( ( qrand( ) % 100 ) * 0.001 + i / static_cast<float>( GRAINS ) );
        }
    }
    float getNextSample( ) {
        float sample = 0;
        for ( int i = 0; i < GRAINS; i++ ) {
            sample += grains[i]->getNextSample( );
        }
        return sample;
    }
    void setSpeed( float speed ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i]->setSpeed( speed );
        }
    }
    void setInitPoint( float ip ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i]->setInitPoint( ip );
        }
    }
    void setGrainSize( float gs ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i]->setGrainSize( gs );
        }
    }
    void setPhase( float ph ) {
        for ( int i = 0; i < GRAINS; i++ ) {
            grains[i]->setPhase( ph );
        }
    }
    void setSampleRate( float sr ) {
        for ( int i = 0; i < GRAINS; i++ )
            grains[i]->setSampleRate( sr );
    }
    void reset( ) {
        for ( int i = 0; i < GRAINS; i++ )
            grains[i]->reset( );
    }
};

#endif // GRAINOSCILLATOR_H
