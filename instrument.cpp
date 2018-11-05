#include "instrument.h"

Instrument* Instrument::_instance = nullptr;

Instrument::Instrument( QObject *parent ) : QObject( parent ) {
    _cpuLoad = 0;
    _tune = 0;
    _initPoint = 0;
    _grainSize = 0;
    _playbackHeadPosition = 0;
    _soundFile = "";
    _gain = 1;
    _outputVolume = 1;
}

Instrument* Instrument::instance( ) {
    if ( !_instance )
        _instance = new Instrument( nullptr );
    return _instance;
}


/* Getters */
double Instrument::cpuLoad( ) {
    return _cpuLoad;
}
double Instrument::tune( ) {
    return _tune;
}
double Instrument::initPoint( ) {
    return _initPoint;
}
double Instrument::grainSize( ) {
    return _grainSize;
}
double Instrument::playbackHeadPosition( ) {
    return _playbackHeadPosition;
}
QString Instrument::soundFile( ) {
    return _soundFile;
}
QVariantList Instrument::bufferL( ) {
    QVariantList b;
    for ( int i = 0; i < _bufferSize; i++ ) {
        b.append( _buffer.getSamples( 0 )[i] );
    }
    return b;
}
QVariantList Instrument::bufferR( ) {
    QVariantList b;
    for ( int i = 0; i < _bufferSize; i++ ) {
        b.append( _buffer.getSamples( 1 )[i] );
    }
    return b;
}
double Instrument::gain( ) {
    return _gain;
}
double Instrument::outputVolume( ) {
    return _outputVolume;
}


/* Setters */
void Instrument::setCpuLoad( double value ) {
    _cpuLoad = value;
    Q_EMIT cpuLoadChanged( );
}
void Instrument::setTune( double value ){
    _tune = value;
    Q_EMIT tuneChanged( );
}
void Instrument::setInitPoint( double value ) {
    _initPoint = value;
    Q_EMIT initPointChanged( );
}
void Instrument::setGrainSize( double value ) {
    _grainSize = value;
    Q_EMIT grainSizeChanged( );
}
void Instrument::setPlaybackHeadPosition( double value ) {
    _playbackHeadPosition = value;
    Q_EMIT playbackHeadPositionChanged( );
}
void Instrument::setSoundFile( QString value ) {
    _soundFile = value;
    Q_EMIT soundFileChanged( );
}
void Instrument::setBuffer( AudioBuffer buff, int bufferSize ) {
    _buffer = buff;
    _bufferSize = bufferSize;
    Q_EMIT bufferChanged( );
}
void Instrument::setGain( double value ) {
    _gain = value;
    Q_EMIT gainChanged( );
}
void Instrument::setOutputVolume( double value ) {
    _outputVolume = value;
    Q_EMIT outputVolumeChanged( );
}

