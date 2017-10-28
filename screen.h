#ifndef SCREEN_H
#define SCREEN_H

#include <inttypes.h>

typedef enum {
    SCREEN_STANDBY,
    SCREEN_MAIN,
    SCREEN_SETUP,

    SCREEN_END
} Screen_t;

extern Screen_t Screen;

typedef enum {
    CLEAR_NOTHING   = 0,
    CLEAR_ALL       = 1,

    CLEAR_END
} ClearMode;

void screenInit(void);

void screenSet(uint8_t value);

void screenUpdate(void);

#endif // SCREEN_H
