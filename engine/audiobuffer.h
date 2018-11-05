#ifndef AUDIOBUFFER_H
#define AUDIOBUFFER_H

#include "floatarray.h"

class AudioBuffer {
private:
    float* buffer;
    int channels;
    int size;
public:
    AudioBuffer( );
    AudioBuffer( float* buf, int ch, int sz );
    ~AudioBuffer();
    void clear( );
    FloatArray getSamples( int channel );
    int getChannels( );
    int getSize( );
    static AudioBuffer create(int channels, int samples);
};

#endif // AUDIOBUFFER_H
