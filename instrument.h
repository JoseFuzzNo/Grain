#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>

/**
 * @brief Clase de interfaz entre el motor de audio y el interfaz grafico.
 * Tiene formato "singleton": solo una instancia permitida.
 */
class Instrument : public QObject {
    Q_OBJECT
    Q_PROPERTY( double cpuLoad READ cpuLoad NOTIFY cpuLoadChanged )
    Q_PROPERTY( double outputVolume READ outputVolume WRITE setOutputVolume NOTIFY outputVolumeChanged )

public:
    static Instrument *instance( );

    /* Getters */
    double cpuLoad( );
    double outputVolume( );

public slots:
    /* Setters */
    void setCpuLoad( double value );
    void setOutputVolume( double value );

signals:
    void cpuLoadChanged( );
    void outputVolumeChanged( );

private:
    explicit Instrument( QObject *parent = nullptr );
    static Instrument *_instance;

    double _cpuLoad;
    double _outputVolume;
};

#endif // INSTRUMENT_H
