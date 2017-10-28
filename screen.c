#include "screen.h"

#include "glcd.h"
#include "tuner.h"

#define STR_BUFSIZE                     20

Screen_t Screen = SCREEN_END;

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

static void drawScreenStandby()
{
    glcdSetXY(56, 20);
    glcdWriteIcon(icon_radio, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
}

static void drawScreenMain()
{
    tunerUpdateStatus();

    uint16_t freq = tunerGetFreq();

    glcdSetXY(0, 4);
    glcdWriteIcon(icon_radio, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    glcdLoadFont(font_digits_32, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(36, 0);
    glcdWriteString(mkNumString(freq, 6, 2, ' '));
}

void screenSet(uint8_t value)
{
    if (Screen != value)
        glcdFill(LCD_COLOR_BLACK);

    switch (value) {
    case SCREEN_STANDBY:
        drawScreenStandby();
        break;
    case SCREEN_MAIN:
        drawScreenMain();
        break;
    default:
        break;
    }

    Screen = value;
}

void screenUpdate(void)
{
    screenSet(Screen);

    glcdUpdateScreen();
}
