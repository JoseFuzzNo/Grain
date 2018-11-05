#include "audiobuffer.h"

AudioBuffer::AudioBuffer( ) :
    buffer( nullptr ),
    channels( 0.0f ),
    size( 0.0f ) {

}
AudioBuffer::AudioBuffer( float* buf, int ch, int sz  ) :
    buffer( buf ),
    channels( ch ),
    size( sz ) {

}
AudioBuffer::~AudioBuffer( ) {

}
void AudioBuffer::clear( ) {
    memset( buffer, 0, size * channels * sizeof( float ) );
}
FloatArray AudioBuffer::getSamples( int channel ) {
    return FloatArray( buffer + channel * size, size );
}
int AudioBuffer::getChannels( ) {
    return channels;
}
int AudioBuffer::getSize( ) {
    return size;
}
AudioBuffer AudioBuffer::create( int channels, int samples ) {
  AudioBuffer buf( new float[channels * samples], channels, samples );
  return buf;
}
