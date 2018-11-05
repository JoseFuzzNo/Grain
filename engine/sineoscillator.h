#ifndef SINEOSCILLATOR_H
#define SINEOSCILLATOR_H

#include "oscillator.h"
#include "math.h"

class SineOscillator : public Oscillator {
private:
    float mul;
    float phase;
    float incr;
public:
  SineOscillator( ) : phase( 0.0f ), incr( 0.0f ) {
      setSampleRate( 44100 );
  }
  SineOscillator( float sr ) : phase( 0.0f ), incr( 0.0f ) {
      setSampleRate( sr );
  }
  void setSampleRate( float sr ) {
      mul = 2 * M_PIf32 / sr;
  }
  void setFrequency( float freq ) {
      incr = freq * mul;
  }
  /**
   * @brief setPhase    Se fuerza la fase del oscilador.
   * @param ph      Fase en radianes.
   */
  void setPhase( float ph ) {
      phase = ph;
      while( phase >= 2 * M_PIf32 )
          phase -= 2 * M_PIf32;
  }
  void reset( ) {
      phase = 0.0f;
  }
  float getPhase( ) {
      return phase;
  }
  float getNextSample( ) {
      float sample = sinf( phase );
      phase += incr;
      if( phase >= 2 * M_PIf32 )
          phase -= 2 * M_PIf32;
      return sample;
  }
};

#endif // SINEOSCILLATOR_H
