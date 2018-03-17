#include "rda580x.h"

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "../i2c.h"
#include "../eeprom.h"

#include "rds.h"

static uint16_t reg02 = RDA580X_02_DHIZ | RDA580X_02_DMUTE | RDA580X_02_SEEKUP | RDA580X_02_SKMODE |
                        RDA5807_02_RDS_EN | 0;
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

    rdsClear();
}

void rda580xSetVolume(int8_t value)
{
    if (value < RDA5807_VOL_MIN)
        value = RDA5807_VOL_MIN;
    if (value > RDA5807_VOL_MAX)
        value = RDA5807_VOL_MAX;

    Tuner.eep.volume = value;

    reg05 &= ~RDA580X_05_VOLUME;
    reg05 |= (value - (value ? 1 : 0));

    rda580xWriteReg(5, reg05);

    rda580xSetMute(!value);
}

void rda580xSetMute(uint8_t value)
{
    reg02 &= ~RDA580X_02_SEEK;

    if (value)
        reg02 &= ~RDA580X_02_DMUTE;
    else
        reg02 |= RDA580X_02_DMUTE;

    rda580xWriteReg(2, reg02);
}

void rda580xSetBass(uint8_t value)
{
    reg02 &= ~RDA580X_02_SEEK;

    if (value)
        reg02 |= RDA580X_02_BASS;
    else
        reg02 &= ~RDA580X_02_BASS;

    rda580xWriteReg(2, reg02);
}

void rda580xSetPower(uint8_t value)
{
    reg02 &= ~RDA580X_02_SEEK;

    if (value)
        reg02 |= RDA580X_02_ENABLE;
    else
        reg02 &= ~RDA580X_02_ENABLE;

    rda580xWriteReg(2, reg02);

    rdsClear();
}

void rda580xUpdateStatus()
{
    I2CStart(RDA5807M_I2C_ADDR);
    I2CWriteByte(0x0A);
    I2CStart(RDA5807M_I2C_ADDR | I2C_READ);

    reg0A = I2CReadWord(I2C_ACK);
    reg0B = I2CReadWord(I2C_ACK);

    // RDS data
    rdsRaw.B1 = I2CReadWord(I2C_ACK);
    rdsRaw.B2 = I2CReadWord(I2C_ACK);
    rdsRaw.B3 = I2CReadWord(I2C_ACK);
    rdsRaw.B4 = I2CReadWord(I2C_NOACK);

    I2CStop();

    Tuner.level = (reg0B & RDA580X_0B_RSSI) >> 9;

    Tuner.STC = (reg0A & RDA580X_0A_STC) ? 1 : 0;
    Tuner.SF = (reg0A & RDA580X_0A_SF) ? 1 : 0;
    Tuner.BLK_E = (reg0A & RDA5807_0A_BLK_E) ? 1 : 0;
    Tuner.ST = (reg0A & RDA580X_0A_ST) ? 1 : 0;

    Tuner.FM_TRUE = (reg0B & RDA580X_0B_FM_TRUE) ? 1 : 0;
    Tuner.FM_READY = (reg0B & RDA580X_0B_FM_READY) ? 1 : 0;

    Tuner.rdsReady = (reg0A & RDA5807_0A_RDSR) &&   // RDS ready
            (reg0A & RDA5807_0A_RDSS) &&            // RDS synchronized
            ((reg0B & RDA5807_0B_BLERA) == 0) &&    // No errors in A
            ((reg0B & RDA5807_0B_BLERB) == 0);      // No errors in B
    Tuner.rdsBlockE = (reg0B & RDA5807_0B_ABCD_E) ? 1 : 0;

    if (Tuner.rdsReady)
        rdsDecode();

    uint16_t chan = reg0A & RDA580X_0A_READCHAN;

    Tuner.eep.freq = chan * RDA5807_CHAN_SPACING + RDA5807_MIN_FREQ;
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

    rdsClear();
}
