#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <QVariant>

/**
 * @brief Clase de interfaz entre el motor de audio y el interfaz grafico.
 * Tiene formato "singleton": solo una instancia permitida.
 */
class Instrument : public QObject {
    Q_OBJECT
    Q_PROPERTY( double cpuLoad READ cpuLoad NOTIFY cpuLoadChanged )
    Q_PROPERTY( double initPoint READ initPoint WRITE setInitPoint NOTIFY initPointChanged )
    Q_PROPERTY( QString soundFile READ soundFile WRITE setSoundFile NOTIFY soundFileChanged )
    Q_PROPERTY( QVariantList grainBuffer READ grainBuffer NOTIFY grainBufferChanged )
    Q_PROPERTY( double outputVolume READ outputVolume WRITE setOutputVolume NOTIFY outputVolumeChanged )

public:
    static Instrument *instance( );

    /* Getters */
    double cpuLoad( );
    double initPoint( );
    QString soundFile( );
    QVariantList grainBuffer( );
    inline QVariantList *grainBufferPointer( ) {
        return &_grainBuffer;
    }
    double outputVolume( );

public slots:
    /* Setters */
    void setCpuLoad( double value );
    void setInitPoint( double value );
    void setSoundFile( QString value );
    void setGrainBuffer( );
    void setOutputVolume( double value );

signals:
    void cpuLoadChanged( );
    void initPointChanged( );
    void soundFileChanged( );
    void grainBufferChanged( );
    void outputVolumeChanged( );

private:
    explicit Instrument( QObject *parent = nullptr );
    static Instrument *_instance;

    double _cpuLoad;
    double _initPoint;
    QString _soundFile;
    QVariantList _grainBuffer;
    double _outputVolume;
};

#endif // INSTRUMENT_H
