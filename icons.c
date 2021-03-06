#include <avr/pgmspace.h>
#include "icons.h"

const uint8_t icon_radio[] PROGMEM = {
    24, 24,
    0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83, 0x86, 0x86, 0x8C,
    0x8C, 0x98, 0x98, 0xB0, 0xB0, 0xE0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x00,
    0xFF, 0x1F, 0xA7, 0xAB, 0xA9, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9,
    0xA9, 0xAB, 0xA7, 0x1F, 0xFF, 0xFF, 0xFF, 0xE7, 0xDB, 0xDB, 0xE7, 0xFF,
    0x7F, 0xFC, 0xF2, 0xEA, 0xCA, 0xCA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xCA,
    0xCA, 0xEA, 0xF2, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xCC, 0xFF, 0x7F,
};

const uint8_t icon_volume[] PROGMEM = {
    24, 24,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE,
    0xFF, 0xFF, 0x00, 0x00, 0x60, 0xE6, 0xCE, 0x9C, 0x38, 0xF0, 0xE0, 0x80,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x66, 0x7E, 0x3C, 0x81, 0xFF, 0x7E, 0x00, 0xFF, 0xFF,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x07, 0x0F, 0x1F, 0x3F, 0x7F,
    0xFF, 0xFF, 0x00, 0x00, 0x06, 0x67, 0x73, 0x39, 0x1C, 0x0F, 0x07, 0x01,
};

const uint8_t icon_mute[] PROGMEM = {
    24, 24,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE,
    0xFF, 0xFF, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0xC1, 0xE3, 0x77, 0x3E, 0x1C, 0x3E, 0x77, 0xE3, 0xC1,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x07, 0x0F, 0x1F, 0x3F, 0x7F,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
