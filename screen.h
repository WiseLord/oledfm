#ifndef SCREEN_H
#define SCREEN_H

#include <inttypes.h>

typedef enum {
    SCREEN_MAIN,
    SCREEN_SETUP,

    SCREEN_END
} Screen;

typedef enum {
    CLEAR_NOTHING   = 0,
    CLEAR_ALL       = 1,

    CLEAR_END
} ClearMode;

void screenInit(void);

void screenShowMain(ClearMode clear);
void screenShowSetup(ClearMode clear);

void screenUpdate(void);
Screen screenGet(void);

#endif // SCREEN_H
