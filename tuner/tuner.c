#include "tuner.h"
#include "rda580x.h"

#include <stddef.h>
#include <avr/eeprom.h>
#include "../eeprom.h"

typedef struct {
    void (*Init)();
    void (*SetPower)(uint8_t value);
    void (*SetFreq)(uint16_t value);
    void (*Seek)(int8_t direction);
    void (*SetVolume)(int8_t value);
    void (*SetMute)(uint8_t value);
    void (*SetBass)(uint8_t value);
    void (*UpdateStatus)();
} TunerClass_t;

static TunerClass_t TunerClass;

void tunerInit(TunerIC ic)
{
    Tuner.eep.ic = ic;
    TunerClass.Init = NULL;
    TunerClass.SetPower = NULL;
    TunerClass.SetFreq = NULL;
    TunerClass.Seek = NULL;
    TunerClass.SetVolume = NULL;
    TunerClass.SetMute = NULL;
    TunerClass.SetBass = NULL;
    TunerClass.UpdateStatus = NULL;

    switch (Tuner.eep.ic) {
    case TUNER_RDA5807:
        TunerClass.Init = rda580xInit;
        TunerClass.SetPower = rda580xSetPower;
        TunerClass.SetFreq = rda580xSetFreq;
        TunerClass.Seek = rda580xSeek;
        TunerClass.SetVolume = rda580xSetVolume;
        TunerClass.SetMute = rda580xSetMute;
        TunerClass.SetBass = rda580xSetBass;
        TunerClass.UpdateStatus = rda580xUpdateStatus;
        break;
    default:
        break;
    }

    if (TunerClass.Init)
        TunerClass.Init();
}

void tunerSetPower(uint8_t value)
{
    if (TunerClass.SetPower)
        TunerClass.SetPower(value);
}

void tunerSetFreq(uint16_t value)
{
    if (TunerClass.SetFreq)
        TunerClass.SetFreq(value);
}

void tunerSeek(int8_t direction)
{
    if (TunerClass.Seek)
        TunerClass.Seek(direction);
}

void tunerSetVolume(int8_t value)
{
    if (TunerClass.SetVolume)
        TunerClass.SetVolume(value);
}

void tunerSetMute(uint8_t value)
{
    if (TunerClass.SetMute)
        TunerClass.SetMute(value);
}

void tunerSetBass(uint8_t value)
{
    if (TunerClass.SetBass)
        TunerClass.SetBass(value);
}

void tunerUpdateStatus()
{
    if (TunerClass.UpdateStatus)
        TunerClass.UpdateStatus();
}
