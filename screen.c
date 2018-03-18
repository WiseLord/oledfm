#include "screen.h"

#include "glcd.h"
#include "tuner/tuner.h"
#include <avr/eeprom.h>
#include "eeprom.h"
#include "tuner/rds.h"

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
    glcdSetXY(0, 0);
    glcdWriteIcon(icon_radio, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    glcdLoadFont(font_ks0066_ru_24, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(36, 2);
    glcdWriteString(mkNumString(tuner.rdFreq, 6, 2, ' '));

    glcdLoadFont(font_matrix_16, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetXY(106, 20);
    glcdWriteString(mkNumString(tuner.volume, 2, 0, ' '));
    glcdSetXY(104, 40);
    glcdWriteIcon(tuner.volume && !tuner.mute ? icon_volume : icon_mute, LCD_COLOR_WHITE, LCD_COLOR_BLACK);

    // stereo/mono/mute test
    glcdSetXY(106, 0);
    if (tuner.bass)
        glcdWriteString("B");
    else
        glcdWriteString("N");
//    if (tuner.mono) {
//        glcdWriteString("M");
//    } else {
//        if (tunerStereo()) {
//            glcdWriteString("S");
//        } else {
//            glcdWriteString("-");
//        }
//    }
//    if (tuner.rds) {
//        glcdWriteString("R");
//    } else {
//        glcdWriteString("-");
//    }

    glcdLoadFont(font_matrix_16, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
    glcdSetFontFixed(12);
    glcdSetXY(0, 48);
    if (rdsGetFlag())
        glcdWriteString(rdsGetText());
    else
        glcdWriteString("        ");
}

void screenSet(uint8_t value)
{
    if (Screen != value)
        glcdFill(LCD_COLOR_BLACK);

    tunerReadStatus();

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
