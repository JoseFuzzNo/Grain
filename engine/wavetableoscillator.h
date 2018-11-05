#ifndef WAVETABLEOSCILLATOR_H
#define WAVETABLEOSCILLATOR_H

#include "oscillator.h"
#include "floatarray.h"

class WavetableOscillator : public Oscillator {
private:
  float multiplier;
  FloatArray wave;
  float acc;
  float inc;
public:
  WavetableOscillator( float sr, const FloatArray wavetable );
  void setSampleRate( float value );
  void setFrequency( float freq );
  float getSample( float phase );
  float getNextSample( );
  void getSamples( float *samples, int size );
  static WavetableOscillator* create( float sr, int size );
  static void destroy( WavetableOscillator* osc );
};

#endif // WAVETABLEOSCILLATOR_H
