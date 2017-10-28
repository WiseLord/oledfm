#include "tuner.h"
#include "rda580x.h"

#include <stddef.h>
#include <avr/eeprom.h>
#include "eeprom.h"

typedef struct {
    void (*Init)();
    void (*SetPower)(uint8_t value);
    void (*SetFreq)(uint16_t value);
    void (*Seek)(int8_t direction);
    void (*SetVolume)(int8_t value);
    void (*SetMute)(uint8_t value);
    void (*SetBass)(uint8_t value);
    void (*UpdateStatus)();
    uint16_t (*GetFreq)();
} Tuner_t;

static Tuner_t tuner;

void tunerInit(TunerIC ic)
{
    tuner.Init = NULL;
    tuner.SetPower = NULL;
    tuner.SetFreq = NULL;
    tuner.Seek = NULL;
    tuner.SetVolume = NULL;
    tuner.SetMute = NULL;
    tuner.SetBass = NULL;
    tuner.UpdateStatus = NULL;
    tuner.GetFreq = NULL;

    switch (ic) {
    case TUNER_RDA5807:
        tuner.Init = rda580xInit;
        tuner.SetPower = rda580xSetPower;
        tuner.SetFreq = rda580xSetFreq;
        tuner.Seek = rda580xSeek;
        tuner.SetVolume = rda580xSetVolume;
        tuner.SetMute = rda580xSetMute;
        tuner.SetBass = rda580xSetBass;
        tuner.UpdateStatus = rda580xUpdateStatus;
        tuner.GetFreq = rda580xGetFreq;
        break;
    default:
        break;
    }

    if (tuner.Init)
        tuner.Init();
}

void tunerSetPower(uint8_t value)
{
    if (tuner.SetPower)
        tuner.SetPower(value);
}

void tunerSetFreq(uint16_t value)
{
    if (tuner.SetFreq)
        tuner.SetFreq(value);
}

void tunerSeek(int8_t direction)
{
    if (tuner.Seek)
        tuner.Seek(direction);
}

void tunerSetVolume(int8_t value)
{
    if (tuner.SetVolume)
        tuner.SetVolume(value);
}

void tunerSetMute(uint8_t value)
{
    if (tuner.SetMute)
        tuner.SetMute(value);
}

void tunerSetBass(uint8_t value)
{
    if (tuner.SetBass)
        tuner.SetBass(value);
}

void tunerUpdateStatus()
{
    if (tuner.UpdateStatus)
        tuner.UpdateStatus();
}

uint16_t tunerGetFreq()
{
    uint16_t ret = 0;

    if (tuner.GetFreq)
        ret = tuner.GetFreq();

    return ret;
}
