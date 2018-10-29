#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QList>
typedef QList<float> FloatArray;


class Oscillator {
public:
    Oscillator( ) {}
    virtual ~Oscillator( ) {}
    virtual float getNextSample( ) { return 0.0f; }
    virtual float getNextSample( float fm ) { return 0.0f; }

    /* Fills @param output with samples */
    virtual void getSamples( float *output, int size ) {
        for( int i=0; i < size; ++i )
            output[i] = getNextSample( );
    }
    virtual void getSamples(FloatArray output){
        for( int i=0; i < output.size( ); ++i )
            output[i] = getNextSample( );
    }
    virtual void getSamples(FloatArray output, FloatArray fm){
        for( int i = 0; i < output.size( ); ++i )
            output[i] = getNextSample( fm[i] );
    }
    virtual void setSampleRate( float value ) {}
    virtual void setFrequency( float value ) {}
    virtual void reset( ) {}
};

#endif // OSCILLATOR_H
