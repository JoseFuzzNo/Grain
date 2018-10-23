#include "instrument.h"

Instrument* Instrument::_instance = 0;

Instrument::Instrument( QObject *parent ) : QObject( parent ) {
    _cpuLoad = 0;
    _outputVolume = 1;
}

Instrument* Instrument::instance( ) {
    if ( !_instance )
        _instance = new Instrument( NULL );
    return _instance;
}


/* Getters */
double Instrument::cpuLoad( ) {
    return _cpuLoad;
}
double Instrument::outputVolume( ) {
    return _outputVolume;
}


/* Setters */
void Instrument::setCpuLoad( double value ) {
    _cpuLoad = value;
    Q_EMIT cpuLoadChanged( );
}
void Instrument::setOutputVolume( double value ) {
    _outputVolume = value;
    Q_EMIT outputVolumeChanged( );
}

