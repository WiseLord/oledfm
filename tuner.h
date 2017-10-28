#ifndef TUNER_H
#define TUNER_H

#include <inttypes.h>

typedef enum {
    TUNER_NONE,
    TUNER_RDA5807,

    TUNER_END
} TunerIC;

void tunerInit(TunerIC ic);
void tunerSetPower(uint8_t value);
void tunerSetFreq(uint16_t value);
void tunerSeek(int8_t direction);
void tunerSetVolume(int8_t value);
void tunerSetMute(uint8_t value);
void tunerSetBass(uint8_t value);
void tunerUpdateStatus();
uint16_t tunerGetFreq();


#endif // TUNER_H
