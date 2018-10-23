#ifndef GRAINPROCESSOR_H
#define GRAINPROCESSOR_H

#include <Processor>
#include "instrument.h"

class GrainProcessor : public QtJack::Processor {
public:
    GrainProcessor( QtJack::Client& client );
    void process( int samples );

private:
    QtJack::AudioPort inL;
    QtJack::AudioPort outL;
    QtJack::AudioPort inR;
    QtJack::AudioPort outR;
    QtJack::AudioRingBuffer ringBuffer;
};

#endif // GRAINPROCESSOR_H
