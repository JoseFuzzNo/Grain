#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <QVariant>
#include "audiobuffer.h"

/**
 * @brief Clase de interfaz entre el motor de audio y el interfaz grafico.
 * Tiene formato "singleton": solo una instancia permitida.
 */
class Instrument : public QObject {
    Q_OBJECT
    Q_PROPERTY( double cpuLoad READ cpuLoad NOTIFY cpuLoadChanged )
    Q_PROPERTY( double tune READ tune WRITE setTune NOTIFY tuneChanged )
    Q_PROPERTY( double initPoint READ initPoint WRITE setInitPoint NOTIFY initPointChanged )
    Q_PROPERTY( double grainSize READ grainSize WRITE setGrainSize NOTIFY grainSizeChanged )
    Q_PROPERTY( double playbackHeadPosition READ playbackHeadPosition WRITE setPlaybackHeadPosition NOTIFY playbackHeadPositionChanged )
    Q_PROPERTY( QString soundFile READ soundFile WRITE setSoundFile NOTIFY soundFileChanged )
    Q_PROPERTY( QVariantList bufferL READ bufferL NOTIFY bufferChanged )
    Q_PROPERTY( QVariantList bufferR READ bufferR NOTIFY bufferChanged )
    Q_PROPERTY( double gain READ gain WRITE setGain NOTIFY gainChanged )
    Q_PROPERTY( double outputVolume READ outputVolume WRITE setOutputVolume NOTIFY outputVolumeChanged )

public:
    static Instrument *instance( );

    /* Getters */
    double cpuLoad( );
    double tune( );
    double initPoint( );
    double grainSize( );
    double playbackHeadPosition( );
    QString soundFile( );
    QVariantList bufferL( );
    QVariantList bufferR( );
    inline AudioBuffer grainBufferPointer( ) {
        return _buffer;
    }
    double gain( );
    double outputVolume( );

public slots:
    /* Setters */
    void setCpuLoad( double value );
    void setTune( double value );
    void setInitPoint( double value );
    void setGrainSize( double value );
    void setPlaybackHeadPosition( double value );
    void setSoundFile( QString value );
    void setBuffer( AudioBuffer, int bufferSize );
    void setGain( double value );
    void setOutputVolume( double value );

signals:
    void cpuLoadChanged( );
    void tuneChanged( );
    void initPointChanged( );
    void grainSizeChanged( );
    void playbackHeadPositionChanged( );
    void soundFileChanged( );
    void bufferChanged( );
    void gainChanged( );
    void outputVolumeChanged( );

private:
    explicit Instrument( QObject *parent = nullptr );
    static Instrument *_instance;

    double _cpuLoad;
    double _tune;
    double _initPoint;
    double _grainSize;
    double _playbackHeadPosition;
    QString _soundFile;
    AudioBuffer _buffer;
    int _bufferSize;
    double _gain;
    double _outputVolume;
};

#endif // INSTRUMENT_H
