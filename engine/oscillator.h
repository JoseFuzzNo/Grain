#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "floatarray.h"

class Oscillator {
public:
    Oscillator( ) {}
    virtual ~Oscillator( ) {}
    virtual float getNextSample( ) { return 0.0f; }
    /**
     * @brief getSamples    Se rellena la salida con las siguientes muestras.
     * @param output    Buffer de salida
     * @param size      Numero de muestras necesitadas
     */
    virtual void getSamples( FloatArray output ) {
        for( int i=0; i < output.getSize( ); ++i )
            output[i] = getNextSample( );
    }
    /**
     * @brief setSampleRate Se configura la frecuencia de muestreo.
     * @param sr    Frecuencia de muestreo en hercios.
     */
    virtual void setSampleRate( float sr ) {}
    /**
     * @brief setFrequency  Se configura la frecuencia del oscilador.
     * @param freq  Frecuencia en hercios.
     */
    virtual void setFrequency( float freq ) {}
    virtual void reset( ) {}
};

#endif // OSCILLATOR_H
