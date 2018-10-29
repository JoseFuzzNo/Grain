#ifndef GRAINPROCESSOR_H
#define GRAINPROCESSOR_H

#include <QObject>
#include <QAudioDecoder>
#include <Processor>
#include "instrument.h"
#include "sineoscillator.h"

class GrainProcessor :  public QObject, public QtJack::Processor {
    Q_OBJECT
public:
    explicit GrainProcessor( QtJack::Client& client, QObject *parent = nullptr );
    void process( int samples );

protected slots:
    void updateSoundFile( );
    void transferSamples( );
    void decodingFinished( );
    void decodingError( QAudioDecoder::Error error );

protected:
    void timerEvent( QTimerEvent* );

private:
    QtJack::AudioPort inL;
    QtJack::AudioPort outL;
    QtJack::AudioPort inR;
    QtJack::AudioPort outR;
    QtJack::AudioRingBuffer ringBuffer;

    QVariantList *grainBuffer;

    QAudioDecoder decoder;

    SineOscillator oscillator;
};

#endif // GRAINPROCESSOR_H
