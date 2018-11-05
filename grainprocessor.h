#ifndef GRAINPROCESSOR_H
#define GRAINPROCESSOR_H

#include <QObject>
#include <QAudioDecoder>
#include <Processor>
#include <math.h>
#include "instrument.h"
#include "sineoscillator.h"
#include "wavetableoscillator.h"
#include "grain.h"
#include "floatarray.h"
#include "audiobuffer.h"

/**
 * @brief Clase de gestion del procesador de audio.
 */
class GrainProcessor :  public QObject, public QtJack::Processor {
    Q_OBJECT
private:
    QtJack::AudioPort inL;
    QtJack::AudioPort outL;
    QtJack::AudioPort inR;
    QtJack::AudioPort outR;

    AudioBuffer grainBuffer;
    int bufferSize;

    QAudioDecoder decoder;

    Grain *grainL;
    Grain *grainR;

public:
    explicit GrainProcessor( QtJack::Client& client, QObject *parent = nullptr );
    /**
     * @brief Funcion de procesado. Se ejecuta cada vez que es necesario generar muestras para llenar el buffer de salida.
     * @param samples   Numero de samples necesarios para llenar el buffer.
     */
    void process( int samples );

protected slots:
    /**
     * @brief Se encarga de configurar y arrancar el decodificador de audio para leer un fichero cuando este cambia.
     */
    void updateSoundFile( );
    /**
     * @brief Cuando hay muestras disponibles en el decodificador se mueven al buffer.
     */
    void transferSamples( );
    /**
     * @brief Cuando el decodificador acaba de leer el fichero se refresca el buffer en el interfaz.
     */
    void decodingFinished( );
    /**
     * @brief Cuando sucede un error de decodificacion se informa por la consola.
     * @param error Tipo de error
     */
    void decodingError( QAudioDecoder::Error error );

protected:
    /**
     * @brief Cada cierto tiempo se muestra informacion sobre el estado del procesador.
     */
    void timerEvent( QTimerEvent* );

};

#endif // GRAINPROCESSOR_H
