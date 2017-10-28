#include "screen.h"

#include "glcd.h"
#include "tuner.h"
#include "eeprom.h"

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
    glcdSetXY(0, 4);
    glcdWriteIcon(icon_radio, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    glcdLoadFont(font_ks0066_ru_24, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(36, 0);
    glcdWriteString(mkNumString(Tuner.eep.freq, 6, 2, ' '));

    glcdLoadFont(font_ks0066_ru_24, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(72, 40);
    glcdWriteString(mkNumString(Tuner.eep.volume, 2, 0, ' '));
    glcdSetXY(104, 40);
    glcdWriteIcon(Tuner.eep.volume ? icon_volume : icon_mute, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    glcdLoadFont(font_ks0066_ru_08, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(0, 32);
    glcdWriteString(mkNumString(Tuner.RDSR, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.STC, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.SF, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.RDSS, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.BLK_E, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.ST, 2, 0, ' '));
    glcdSetXY(0, 40);
    glcdWriteString(mkNumString(Tuner.FM_TRUE, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.FM_READY, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.ABCD_E, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.BLERA, 2, 0, ' '));
    glcdWriteString(mkNumString(Tuner.BLERB, 2, 0, ' '));
}

void screenSet(uint8_t value)
{
    if (Screen != value)
        glcdFill(LCD_COLOR_BLACK);

    tunerUpdateStatus();

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
