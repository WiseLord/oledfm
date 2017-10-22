#include "rda580x.h"

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "i2c.h"

#ifdef _RDS
#include "rds.h"
#endif

static uint16_t reg02 = RDA580X_02_DHIZ | RDA580X_02_DMUTE | RDA580X_02_SEEKUP | RDA580X_02_SKMODE |
                        RDA5807_02_RDS_EN | RDA5807_02_NEW_METHOD;
static uint16_t reg03 = RDA580X_03_BAND_US_EUROPE | RDA580X_03_SPACE_50;
static uint16_t reg04 = 0;
static uint16_t reg05 = (RDA5807_05_SEEKTH & (0b1000 << 8)) | RDA580X_05_LNA_PORT_SEL_LNAP;
static uint16_t reg07 = RDA5807_07_TH_SOFRBLEND | RDA5807_07_SOFTBLEND_EN;

static uint16_t reg0A = 0;
static uint16_t reg0B = 0;

static void rda580xWriteReg(uint8_t reg, uint16_t data)
{
    I2CStart(RDA5807M_I2C_ADDR);
    I2CWriteByte(reg);
    I2CWriteByte(data >> 8);
    I2CWriteByte(data & 0xFF);
    I2CStop();
}

void rda580xInit(void)
{
    rda580xWriteReg(2, reg02);
    rda580xWriteReg(3, reg03);
    rda580xWriteReg(4, reg04);
    rda580xWriteReg(5, reg05);
    rda580xWriteReg(7, reg07);
    _delay_ms(500);
}

void rda580xSetFreq(uint16_t freq)
{
    uint16_t chan = (freq - RDA5807_MIN_FREQ) / RDA5807_CHAN_SPACING;

    reg02 &= ~RDA580X_02_SEEK;

    reg03 = chan << 6;
    reg03 |= RDA580X_03_TUNE | RDA580X_03_BAND_US_EUROPE | RDA580X_03_SPACE_50;

    rda580xWriteReg(2, reg02);
    rda580xWriteReg(3, reg03);
}

void rda580xSetVolume(int8_t value)
{
    reg05 &= ~RDA580X_05_VOLUME;
    reg05 |= value;

    rda580xWriteReg(5, reg05);
}

void rda580xSetMute(uint8_t value)
{
    if (value)
        reg02 &= ~RDA580X_02_DMUTE;
    else
        reg02 |= RDA580X_02_DMUTE;

    rda580xWriteReg(2, reg02);
}

void rda580xSetBass(uint8_t value)
{
    if (value)
        reg02 |= RDA580X_02_BASS;
    else
        reg02 &= ~RDA580X_02_BASS;

    rda580xWriteReg(2, reg02);
}

void rda580xPowerOn(void)
{
    reg02 |= RDA580X_02_ENABLE;

    rda580xWriteReg(2, reg02);
}

void rda580xPowerOff(void)
{
    reg02 &= ~RDA580X_02_ENABLE;

    rda580xWriteReg(2, reg02);
}

void rda580xUpdateStatus()
{
    I2CStart(RDA5807M_I2C_ADDR);
    I2CWriteByte(0x0A);
    I2CStart(RDA5807M_I2C_ADDR | I2C_READ);
    reg0A = I2CReadByte(I2C_ACK);
    reg0A <<= 8;
    reg0A |= I2CReadByte(I2C_ACK);
    reg0B = I2CReadByte(I2C_ACK);
    reg0B <<= 8;
    reg0B |= I2CReadByte(I2C_NOACK);
    I2CStop();
}

uint8_t rda580xIsStereo()
{
    return (reg0A & RDA580X_0A_ST) ? 1 : 0;
}

uint8_t rda580xGetLevel()
{
    return (reg0B & RDA580X_0B_RSSI) >> 9;
}

uint8_t rda580xGetFmReady()
{
    return (reg0B & RDA580X_0B_FM_READY) ? 1 : 0;
}

uint8_t rda580xIsStation()
{
    return (reg0B & RDA580X_0B_FM_TRUE) ? 1 : 0;
}

uint8_t rda580xGetSTC()
{
    return (reg0A & RDA580X_0A_STC) ? 1 : 0;
}

uint8_t rda580xGetSF()
{
    return (reg0A & RDA580X_0A_SF) ? 1 : 0;
}

uint8_t rda580xGetRDSR()
{
    return (reg0A & RDA5807_0A_RDSR) ? 1 : 0;
}

uint16_t rda580xGetFmFreq()
{
    uint16_t chan = reg0A & RDA580X_0A_READCHAN;

    return chan * RDA5807_CHAN_SPACING + RDA5807_MIN_FREQ;
}

void rda580xSeek(int8_t direction)
{
    reg02 |= RDA580X_02_SEEK;

    if (direction > 0) {
        reg02 |= RDA580X_02_SEEKUP;
    } else {
        reg02 &= ~RDA580X_02_SEEKUP;
    }
    rda580xWriteReg(2, reg02);
}
