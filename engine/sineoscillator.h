#ifndef SINEOSCILLATOR_H
#define SINEOSCILLATOR_H

#include "oscillator.h"
#include <QtMath>

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
  float getNextSample( float fm ) {
      float sample = sinf( phase );
      phase += incr + fm;
    if( phase >= 2 * M_PIf32 )
        phase -= 2 * M_PI;
    return sample;
  }
  static SineOscillator* create( float sr ) {
      return new SineOscillator( sr );
  }
  static void destroy( SineOscillator* osc ) {
      delete osc;
  }
};

#endif // SINEOSCILLATOR_H
