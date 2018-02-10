#include "ssd1306.h"

#include "pins.h"

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "glcd.h"

static uint8_t fb[SSD1306_BUFFERSIZE];

static const uint8_t initSeq[] PROGMEM = {
    SSD1306_DISPLAY_OFF,
    SSD1306_SETDISPLAYCLOCKDIV,
    0x80,
    SSD1306_SETMULTIPLEX,
    (SSD1306_HEIGHT - 1),
    SSD1306_SETDISPLAYOFFSET,
    0x00,
    SSD1306_SETSTARTLINE | 0x00,
    SSD1306_MEMORYMODE,
    SSD1306_MEMORYMODE_HORISONTAL,
#ifdef SSD1306_ROTATE_180
    SSD1306_SEGREMAP_ON,
    SSD1306_COMSCANDEC,
#else
    SSD1306_SEGREMAP_OFF,
    SSD1306_COMSCANINC,
#endif
    SSD1306_SETCOMPINS,
#if SSD1306_HEIGHT == 64
    0x12,
#else
    0x02,
#endif
    SSD1306_SETCONTRAST,
    0x8F,
    SSD1306_SETPRECHARGE,
    0x1F,
    SSD1306_SETVCOMDETECT,
    0x40,
    SSD1306_ENTDISPLAY_RAM,
    SSD1306_NORMALDISPLAY,
    SSD1306_CHARGEPUMP,
    0x14,
    SSD1306_SCROLL_DEACTIVATE,
    SSD1306_DISPLAY_ON,
};

static const uint8_t dispAreaSeq[] PROGMEM = {
    SSD1306_COLUMNADDR,
    0x00,
    0x7F,
    SSD1306_PAGEADDR,
    0x00,
    0x07,
};

static void _I2CWriteByte(uint8_t data)
{
    uint8_t i = 0;

    // Data bits
    for (i = 0; i < 8; i++) {
        if (data & 0x80)
            DDR(SSD1306_SDA) &= ~SSD1306_SDA_LINE;  // Pullup SDA = 1
        else
            DDR(SSD1306_SDA) |= SSD1306_SDA_LINE;   // Active SDA = 0
        _delay_us(1);
        DDR(SSD1306_SCK) &= ~SSD1306_SCK_LINE;      // Pullup SCL = 1
        _delay_us(1);
        DDR(SSD1306_SCK) |= SSD1306_SCK_LINE;       // Active SCL = 0
        data <<= 1;
    }
    // ACK bit
    DDR(SSD1306_SDA) &= ~SSD1306_SDA_LINE;          // Pullup SDA = 1
    _delay_us(1);
    DDR(SSD1306_SCK) &= ~SSD1306_SCK_LINE;          // Pullup SCL = 1
    _delay_us(1);
    DDR(SSD1306_SCK) |= SSD1306_SCK_LINE;           // Active SCL = 0

    return;
}

static void _I2CStart(uint8_t addr)
{
    DDR(SSD1306_SCK) &= ~SSD1306_SCK_LINE;          // Pullup SCL = 1
    DDR(SSD1306_SDA) &= ~SSD1306_SDA_LINE;          // Pullup SDA = 1
    _delay_us(1);
    DDR(SSD1306_SDA) |= SSD1306_SDA_LINE;           // Active SDA = 0
    _delay_us(1);
    DDR(SSD1306_SCK) |= SSD1306_SCK_LINE;           // Active SCL = 0

    _I2CWriteByte(addr);

    return;
}

static void _I2CStop(void)
{
    DDR(SSD1306_SCK) |= SSD1306_SCK_LINE;           // Active SCL = 0
    DDR(SSD1306_SDA) |= SSD1306_SDA_LINE;           // Active SDA = 0
    _delay_us(1);
    DDR(SSD1306_SCK) &= ~SSD1306_SCK_LINE;          // Pullup SCL = 1
    _delay_us(1);
    DDR(SSD1306_SDA) &= ~SSD1306_SDA_LINE;          // Pullup SDA = 1

    return;
}

static void ssd1306SendCmd(uint8_t cmd)
{
    _I2CWriteByte(cmd);

    return;
}

static void ssd1306Clear(void)
{
    uint16_t i;
    uint8_t *fbP = fb;

    for (i = 0; i < SSD1306_BUFFERSIZE; i++)
        *fbP++ = 0x00;

    return;
}

void ssd1306Init(void)
{
    uint8_t i;

    ssd1306Clear();
    ssd1306UpdateFb();

    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_COMMAND);

    for (i = 0; i < sizeof(initSeq); i++)
        ssd1306SendCmd(pgm_read_byte(&initSeq[i]));

    _I2CStop();

    glcdOpts.width = SSD1306_WIDTH;
    glcdOpts.height = SSD1306_HEIGHT;
    glcdOpts.orientation = LCD_Orientation_Landscape_1;

    return;
}

void ssd1306Sleep(void)
{
    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_COMMAND);

    ssd1306SendCmd(SSD1306_DISPLAY_OFF);

    _I2CStop();
}

void ssd1306Wakeup(void)
{
    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_COMMAND);

    ssd1306SendCmd(SSD1306_DISPLAY_ON);

    _I2CStop();
}

void ssd1306DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
    uint8_t bit;
    uint8_t *fbP;

    if (x >= SSD1306_WIDTH)
        return;
    if (y >= SSD1306_HEIGHT)
        return;

    fbP = &fb[(y >> 3) * SSD1306_WIDTH + x];

    bit = 1 << (y & 0x07);

    if (color)
        *fbP |= bit;
    else
        *fbP &= ~bit;

    return;
}

void ssd1306DrawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
    // TODO: Optimize this
    uint16_t x, y;

    for (x = x0; x <= x1; x++) {
        for (y = y0; y <= y1; y++) {
            ssd1306DrawPixel(x, y, color);
        }
    }
}

void ssd1306WriteChar(const uint8_t *chOft, uint8_t fwd, uint8_t swd)
{
    // TODO: Optimize this
    uint8_t i;
    uint8_t j;
    uint8_t k;
    uint8_t pgmData;

    for (j = 0; j < glcdOpts.fp.height; j++) {
        for (i = 0; i < fwd; i++) {
            if (i >= swd)
                pgmData = 0x00;
            else
                pgmData = pgm_read_byte(chOft + (swd * j) + i);
            for (k = 0; k < 8; k++) {
                if (pgmData & 0x01) {
                    ssd1306DrawPixel(glcdOpts.x + i, glcdOpts.y + (8 * j + k), glcdOpts.fp.color);
                } else {
                    ssd1306DrawPixel(glcdOpts.x + i, glcdOpts.y + (8 * j + k), glcdOpts.fp.bgColor);
                }
                pgmData >>= 1;
            }
        }
    }
}

void ssd1306WriteIcon(const uint8_t *icon, uint16_t color, uint16_t bgColor)
{
    // TODO: Optimize this
    uint8_t i;
    uint8_t j;
    uint8_t k;
    uint8_t pgmData;

    uint8_t width = pgm_read_byte(icon++);
    uint8_t height = pgm_read_byte(icon++);

    for (i = 0; i < width; i++) {
        for (j = 0; j < height / 8; j++) {
            pgmData = pgm_read_byte(icon + (width * j) + i);
            for (k = 0; k < 8; k++) {
                if (pgmData & 0x01) {
                    ssd1306DrawPixel(glcdOpts.x + i, glcdOpts.y + (8 * j + k), color);
                } else {
                    ssd1306DrawPixel(glcdOpts.x + i, glcdOpts.y + (8 * j + k), bgColor);
                }
                pgmData >>= 1;
            }
        }
    }
}

void ssd1306DrawColorMap(void)
{
    // TODO
}

void ssd1306UpdateFb(void)
{
    uint16_t i;
    uint8_t *fbP = fb;

    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_COMMAND);

    for (i = 0; i < sizeof(dispAreaSeq); i++)
        ssd1306SendCmd(pgm_read_byte(&dispAreaSeq[i]));

    _I2CStop();

    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_DATA_SEQ);

    for (i = 0; i < SSD1306_BUFFERSIZE; i++)
        _I2CWriteByte(*fbP++);

    _I2CStop();

    return;
}

void ssd1306SetBrightness(uint8_t br)
{
    uint8_t rawBr = 255;

    if (br < SSD1306_MAX_BRIGHTNESS)
        rawBr = br * 8;

    _I2CStart(SSD1306_I2C_ADDR);
    _I2CWriteByte(SSD1306_I2C_COMMAND);

    ssd1306SendCmd(SSD1306_SETCONTRAST);
    ssd1306SendCmd(rawBr);

    _I2CStop();

    return;
}
