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
    Q_PROPERTY( QVariantList buffer READ buffer NOTIFY bufferChanged )
    Q_PROPERTY( double gain READ gain WRITE setGain NOTIFY gainChanged )
    Q_PROPERTY( double outputVolume READ outputVolume WRITE setOutputVolume NOTIFY outputVolumeChanged )

public:
    static Instrument *instance( );

    /* Getters */
    double cpuLoad( );
    double initPoint( );
    QString soundFile( );
    QVariantList buffer( );
    inline QVariantList *grainBufferPointer( ) {
        return &_buffer;
    }
    double gain( );
    double outputVolume( );

public slots:
    /* Setters */
    void setCpuLoad( double value );
    void setInitPoint( double value );
    void setSoundFile( QString value );
    void setBuffer( );
    void setGain( double value );
    void setOutputVolume( double value );

signals:
    void cpuLoadChanged( );
    void initPointChanged( );
    void soundFileChanged( );
    void bufferChanged( );
    void gainChanged( );
    void outputVolumeChanged( );

private:
    explicit Instrument( QObject *parent = nullptr );
    static Instrument *_instance;

    double _cpuLoad;
    double _initPoint;
    QString _soundFile;
    QVariantList _buffer;
    double _gain;
    double _outputVolume;
};

#endif // INSTRUMENT_H
