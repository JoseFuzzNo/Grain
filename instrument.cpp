#include "instrument.h"

Instrument* Instrument::_instance = nullptr;

Instrument::Instrument( QObject *parent ) : QObject( parent ) {
    _cpuLoad = 0;
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
double Instrument::initPoint( ) {
    return _initPoint;
}
QString Instrument::soundFile( ) {
    return _soundFile;
}
QVariantList Instrument::grainBuffer( ) {
    return _grainBuffer;
}
double Instrument::outputVolume( ) {
    return _outputVolume;
}


/* Setters */
void Instrument::setCpuLoad( double value ) {
    _cpuLoad = value;
    Q_EMIT cpuLoadChanged( );
}
void Instrument::setInitPoint( double value ) {
    _initPoint = value;
    Q_EMIT initPointChanged( );
}
void Instrument::setSoundFile( QString value ) {
    _soundFile = value;
    Q_EMIT soundFileChanged( );
}
void Instrument::setGrainBuffer( ) {
    Q_EMIT grainBufferChanged( );
}
void Instrument::setOutputVolume( double value ) {
    _outputVolume = value;
    Q_EMIT outputVolumeChanged( );
}

