#ifndef EEPROM_H
#define EEPROM_H

#include <inttypes.h>

typedef struct {
    uint16_t freq;
    uint8_t volume;
    uint8_t ic;
} EepTuner_t;

typedef struct {
    EepTuner_t eep;
    uint8_t level;

    uint8_t RDSR:1;
    uint8_t STC:1;
    uint8_t SF:1;
    uint8_t RDSS:1;
    uint8_t BLK_E:1;
    uint8_t ST:1;

    uint8_t FM_TRUE:1;
    uint8_t FM_READY:1;
    uint8_t ABCD_E:1;
    uint8_t BLERA:2;
    uint8_t BLERB:2;
} Tuner_t;

extern Tuner_t Tuner;

#define EEPROM_TUNER        0x00

void eepSaveTuner();
void eepRestoreTuner();

#endif // EEPROM_H
