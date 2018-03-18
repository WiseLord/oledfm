#ifndef EEPROM_H
#define EEPROM_H

#include <inttypes.h>

// FM tuner parameters valus
#define EEPROM_FM_TUNER             0x70
#define EEPROM_FM_CTRL              (EEPROM_FM_TUNER + 0x01)
#define EEPROM_FM_STEP1             (EEPROM_FM_TUNER + 0x02)
#define EEPROM_FM_STEP2             (EEPROM_FM_TUNER + 0x03)
#define EEPROM_FM_FREQ_MIN          (EEPROM_FM_TUNER + 0x04)
#define EEPROM_FM_FREQ_MAX          (EEPROM_FM_TUNER + 0x06)
#define EEPROM_FM_FREQ              (EEPROM_FM_TUNER + 0x08)
#define EEPROM_FM_MONO              (EEPROM_FM_TUNER + 0x0A)
#define EEPROM_FM_RDS               (EEPROM_FM_TUNER + 0x0B)
#define EEPROM_FM_VOLUME            (EEPROM_FM_TUNER + 0x0C)
#define EEPROM_FM_BASS              (EEPROM_FM_TUNER + 0x0D)
#define EEPROM_FM_TUNER_SIZE        14

// FM stations
#define EEPROM_FAV_STATIONS         (EEPROM_FM_TUNER + 0x10)
#define EEPROM_STATIONS             (EEPROM_FM_TUNER + 0x24)

#endif // EEPROM_H
