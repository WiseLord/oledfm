#include "eeprom.h"
#include <avr/eeprom.h>
#include "tuner.h"

Tuner_t Tuner;

void eepSaveTuner()
{
    eeprom_update_block(&Tuner.eep, (void*)EEPROM_TUNER, sizeof(EepTuner_t));
}

void eepRestoreTuner()
{
    eeprom_read_block(&Tuner.eep, (void*)EEPROM_TUNER, sizeof(EepTuner_t));
}
