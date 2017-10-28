#include "screen.h"

#include "glcd.h"
#include "tuner.h"

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
    tunerUpdateStatus();

    uint16_t freq = tunerGetFreq();

    if (clear == CLEAR_ALL)
        glcdFill(LCD_COLOR_BLACK);

    glcdSetXY(0, 4);
    glcdWriteIcon(icon_radio, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    glcdLoadFont(font_digits_32, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(36, 0);
    glcdWriteString(mkNumString(freq, 6, 2, ' '));

    screen = SCREEN_MAIN;
}

void screenShowSetup(ClearMode clear)
{
    if (clear == CLEAR_ALL)
        glcdFill(LCD_COLOR_BLACK);
    glcdLoadFont(font_ks0066_ru_24, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(0, 0);
    glcdWriteString("Setup mode");
    glcdSetXY(0, 24);
    glcdWriteIcon(icon_pointer, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdDrawRing(80, 50, 10, LCD_COLOR_WHITE);
    screen = SCREEN_SETUP;
}

void screenUpdate(void)
{
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
    glcdUpdateScreen();
}

Screen screenGet(void)
{
    return screen;
}
