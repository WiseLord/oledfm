#include "screen.h"

//#include "glcd.h"

#define STR_BUFSIZE                     20

static Screen screen = SCREEN_END;

static char strbuf[STR_BUFSIZE + 1];

static char *mkNumString(int32_t number, uint8_t width, uint8_t dot, uint8_t lead)
{
    uint8_t numdiv;
    int8_t i;

    for (i = 0; i < width; i++)
        strbuf[i] = lead;
    strbuf[width] = '\0';
    i = 0;

    while (number > 0 || i < dot + 1 + !!dot) {
        if (number < 0) {
            strbuf[width - 1 - i] = '-';
        } else {
            numdiv = number % 10;
            number /= 10;
            strbuf[width - 1 - i] = numdiv + 0x30;
        }
        i++;
        if (dot == i) {
            strbuf[width - 1 - i] = '.';
            i++;
        }
    }
    return strbuf;
}

void screenInit(void)
{
}

void screenShowMain(ClearMode clear)
{
    screen = SCREEN_MAIN;
}

void screenShowSetup(ClearMode clear)
{
    screen = SCREEN_SETUP;
}

void screenUpdate(void)
{
    mkNumString(3, 5, 1, ' ');
    switch (screen) {
    case SCREEN_MAIN:
        screenShowMain(CLEAR_NOTHING);
        break;
    case SCREEN_SETUP:
        screenShowSetup(CLEAR_NOTHING);
        break;
    default:
        break;
    }
}

Screen screenGet(void)
{
    return screen;
}
