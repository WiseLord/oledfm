#include "rda580x.h"
#include "tuner.h"

#include <avr/pgmspace.h>
#include "../i2c.h"

#ifdef _RDS
#include "rds.h"
#endif

static uint8_t wrBuf[14] = {
    RDA580X_DHIZ,
    RDA580X_SKMODE | RDA580X_CLK_MODE_32768 | RDA5807_NEW_METHOD,
    0,
    0,
    0,
    0,
    0b1000 & RDA5807_SEEKTH,
    RDA580X_LNA_PORT_SEL_LNAP | RDA580X_VOLUME,
    0,
    0,
    (0x40 & RDA5807_TH_SOFRBLEND),
    0,
    0,
    0,
};

static uint8_t band = RDA580X_BAND_US_EUROPE;
static uint16_t fBL = 8700;

static void rda580xWriteReg(uint8_t reg)
{
    uint8_t *wrAddr = &wrBuf[2 * reg - 4];

    I2CStart(RDA5807M_I2C_RAND_ADDR);
    I2CWriteByte(reg);
    I2CWriteByte(*wrAddr++);
    I2CWriteByte(*wrAddr++);
    I2CStop();
}

void rda580xInit()
{
    rda580xSetMono(tuner.mono);
#ifdef _RDS
    rda580xSetRds(tuner.rds);
#endif
    if (tuner.ic == TUNER_RDA5807 && (tuner.ctrl & TUNER_DFREQ)) {
        wrBuf[11] |= RDA5807_FREQ_MODE;
    } else {
        wrBuf[11] &= RDA5807_FREQ_MODE;
    }
    rda580xWriteReg(7);

    if (tuner.ctrl & TUNER_DE) {
        wrBuf[4] &= ~RDA580X_DE;
    } else {
        wrBuf[4] |= RDA580X_DE;
    }

    if (tuner.ctrl & TUNER_SMUTE) {
        wrBuf[4] |= RDA580X_SOFTMUTE_EN;
    } else {
        wrBuf[4] &= ~RDA580X_SOFTMUTE_EN;
    }
    rda580xWriteReg(4);

    if (tuner.ctrl & TUNER_BL) {
        fBL = 7600;
        band = RDA580X_BAND_JAPAN;
    } else {
        if (tuner.fMin < 8700) {
            fBL = 7600;
            band = RDA580X_BAND_WORLDWIDE;
        }
    }
}

void rda580xSetFreq()
{
    if (wrBuf[11] & RDA5807_FREQ_MODE) {
        uint16_t df = (tuner.freq - 5000) * 10;
        wrBuf[13] = df & 0xFF;
        wrBuf[12] = df >> 8;
        rda580xWriteReg(8);

        wrBuf[3] = RDA580X_TUNE | RDA580X_BAND_EASTEUROPE | RDA580X_SPACE_100;
    } else {
        // Freq in grid
        uint16_t chan = (tuner.freq - fBL) / RDA5807_CHAN_SPACING;
        wrBuf[2] = chan >> 2; // 8 MSB
        wrBuf[3] = ((chan & 0x03) << 6) | RDA580X_TUNE | band | RDA580X_SPACE_100;
    }
    rda580xWriteReg(3);
}

void rda580xReadStatus()
{
    I2CStart(RDA5807M_I2C_SEQ_ADDR | I2C_READ);
    for (uint8_t i = 0; i < RDA5807_RDBUF_SIZE - 1; i++)
        tunerRdbuf[i] = I2CReadByte(I2C_ACK);
    tunerRdbuf[RDA5807_RDBUF_SIZE - 1] = I2CReadByte(I2C_NOACK);
    I2CStop();

    // Get RDS data
#ifdef _RDS
    if (tuner.rds) {
        // If RDS ready and sync flag are set
        if ((tunerRdbuf[0] & RDA5807_RDSR) && (tunerRdbuf[0] & RDA5807_RDSS)) {
            // If there are no non-correctable errors in blocks A-D
            if (    (tunerRdbuf[3] & RDA5807_BLERA) != RDA5807_BLERA &&
                    (tunerRdbuf[3] & RDA5807_BLERB) != RDA5807_BLERB ) {
                // Send rdBuf[4..11] as 16-bit blocks A-D
                rdsDecode(&tunerRdbuf[4]);
            }
        }
    }
#endif
    uint16_t chan = tunerRdbuf[0] & RDA580X_READCHAN_9_8;
    chan <<= 8;
    chan |= tunerRdbuf[1];

    if (wrBuf[11] & RDA5807_FREQ_MODE) {
        tuner.rdFreq = tuner.freq;
    } else {
        uint16_t chan = tunerRdbuf[0] & RDA580X_READCHAN_9_8;
        chan <<= 8;
        chan |= tunerRdbuf[1];
        tuner.rdFreq = chan * RDA5807_CHAN_SPACING + fBL;
    }
}

void rda580xSetVolume(int8_t value)
{
    if (value)
        wrBuf[7] = RDA580X_LNA_PORT_SEL_LNAP | (value - 1);
    else
        rda580xSetMute(1);

    rda580xWriteReg(5);
}

void rda580xSetMute(uint8_t value)
{
    if (value)
        wrBuf[0] &= ~RDA580X_DMUTE;
    else
        wrBuf[0] |= RDA580X_DMUTE;

    rda580xWriteReg(2);
}

void rda580xSetBass(uint8_t value)
{
    if (value) {
        wrBuf[0] |= RDA5807_BASS;
    } else {
        wrBuf[0] &= ~RDA5807_BASS;
    }

    rda580xWriteReg(2);
}

void rda580xSetMono(uint8_t value)
{
    if (value) {
        wrBuf[0] |= RDA580X_MONO;
    } else {
        wrBuf[0] &= ~RDA580X_MONO;
    }

    rda580xWriteReg(2);
}

#ifdef _RDS
void rda580xSetRds(uint8_t value)
{
    rdsDisable();

    if (value) {
        wrBuf[1] |= RDA5807_RDS_EN;
    } else {
        wrBuf[1] &= ~RDA5807_RDS_EN;
    }

    rda580xWriteReg(2);
}
#endif

void rda580xSetPower(uint8_t value)
{
    if (value) {
        wrBuf[1] |= RDA580X_ENABLE;
    } else {
        wrBuf[1] &= ~RDA580X_ENABLE;
    }

    rda580xWriteReg(2);
}

void rda580xSeek(int8_t direction)
{
    if (tuner.ic == TUNER_RDA5807 && (tuner.ctrl & TUNER_DFREQ)) {
        tunerChangeFreq(direction);
        return;
    }

    wrBuf[0] |= RDA580X_SEEK;

    if (direction > 0) {
        wrBuf[0] |= RDA580X_SEEKUP;
    } else {
        wrBuf[0] &= ~RDA580X_SEEKUP;
    }
    rda580xWriteReg(2);

    wrBuf[0] &= ~RDA580X_SEEK;
}
