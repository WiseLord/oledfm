#ifndef RDA5807X_H
#define RDA5807X_H

#include <inttypes.h>

#define RDA5807M_I2C_ADDR                   0x22

// Write mode register values

// 00 register
#define RDA580X_00_CHIPID                   0xFF00  // Chip ID

// 02 register
#define RDA580X_02_DHIZ                     0x8000  // Audio out enable (1) / High impedance (0)
#define RDA580X_02_DMUTE                    0x4000  // Audio unmuted (1) / muted (0)
#define RDA580X_02_MONO                     0x2000  // Mono mode (1) / stereo mode (0)
#define RDA580X_02_BASS                     0x1000  // Bass boost (1)
#define RDA5807_02_RCLK_NON_CAL_MODE        0x0800  // RCLK always on (0)
#define RDA580X_02_RCLK_DIR_IN_MODE         0x0400  // RCLK direct input mode (1)
#define RDA580X_02_SEEKUP                   0x0200  // Seek up (0) / down (1)
#define RDA580X_02_SEEK                     0x0100  // Stop seek (0) / start seek in SEEKUP direction (1)
#define RDA580X_02_SKMODE                   0x0080  // Stop seeking on band limit (1)
#define RDA580X_02_CLK_MODE                 0x0070  // Select clock mode
    #define RDA580X_02_CLK_MODE_32768       0x0000  // Select quartz frequency
    #define RDA580X_02_CLK_MODE_12M         0x0010
    #define RDA580X_02_CLK_MODE_13M         0x0020
    #define RDA580X_02_CLK_MODE_19M2        0x0030
    #define RDA580X_02_CLK_MODE_24M         0x0050
    #define RDA580X_02_CLK_MODE_26M         0x0060
    #define RDA580X_02_CLK_MODE_38M4        0x0070
#define RDA5807_02_RDS_EN                   0x0008  // RDS/RBDS enable (1)
#define RDA5807_02_NEW_METHOD               0x0004  // New demodulation method (1)
#define RDA580X_02_SOFT_RESET               0x0002  // Reset settings (1)
#define RDA580X_02_ENABLE                   0x0001  // Power on radio (1)

// 03 register
#define RDA580X_03_CHAN                     0xFFC0  // Channel
#define RDA5807_03_DIRECT_MODE              0x0020  // Direct mode (1), only used when test
#define RDA580X_03_TUNE                     0x0010  // Tune enable (1)
#define RDA580X_03_BAND                     0x00C0  // Tuner band selection
    #define RDA580X_03_BAND_US_EUROPE       0x0000  // 87..108 MHz
    #define RDA580X_03_BAND_JAPAN           0x0040  // 76..97 MHz
    #define RDA580X_03_BAND_WORLDWIDE       0x0080  // 76..108 MHz
    #define RDA580X_03_BAND_EASTEUROPE      0x00C0  // 65..76 MHz
#define RDA580X_03_SPACE                    0x0003  // Stations grid selection
    #define RDA580X_03_SPACE_100            0x0000  // 100kHz step
    #define RDA580X_03_SPACE_200            0x0001  // 200kHz step
    #define RDA580X_03_SPACE_50             0x0002  // 50kHz step
    #define RDA580X_03_SPACE_25             0x0003  // 25kHz step

// 04 register
#define RDA580X_04_STCIEN                   0x4000  // Enable low pulse on GPIO2 when interrupt occurs (1)
#define RDA580X_04_DE                       0x0800  // De-emphasis 75us (0) / 50us (1)
#define RDA580X_04_SOFTMUTE_EN              0x0200  // Softmute enable (1)
#define RDA580X_04_AFCD                     0x0100  // AFC disable (1)
#define RDA580X_04_I2S_ENABLED              0x0040  // I2S bus enable (1)
#define RDA580X_04_GPIO3                    0x0030  // GPIO3 control
    #define RDA580X_04_GPIO3_HI_IMP         0x0000  // GPIO3 high impedance
    #define RDA580X_04_GPIO3_ST_IND         0x0001  // GPIO3 as stereo indicator
    #define RDA580X_04_GPIO3_LO             0x0010  // GPIO3 Low level
    #define RDA580X_04_GPIO3_HI             0x0011  // GPIO3 HIGH level
#define RDA580X_04_GPIO2                    0x000C  // GPIO2 control
    #define RDA580X_04_GPIO2_HI_IMP         0x0000  // GPIO2 high impedance
    #define RDA580X_04_GPIO2_ST_IND         0x0004  // GPIO2 interrupt (INT)
    #define RDA580X_04_GPIO2_LO             0x0008  // GPIO2 Low level
    #define RDA580X_04_GPIO2_HI             0x000C  // GPIO2 HIGH level
#define RDA580X_04_GPIO1                    0x0003  // GPIO1 control
    #define RDA580X_04_GPIO1_HI_IMP         0x0000  // GPIO1 high impedance
    #define RDA580X_04_GPIO1_ST_IND         0x0001  // GPIO1 reserved
    #define RDA580X_04_GPIO1_LO             0x0002  // GPIO1 Low level
    #define RDA580X_04_GPIO1_HI             0x0003  // GPIO1 HIGH level

// 05 register
#define RDA5807_05_INT_MODE                 0x8000  // 5ms interrupt for RDSIEN on RDS ready (0)
#define RDA5807_05_SEEKTH                   0x0F00  // Seek SNR threshold, 4bits, default 1000=32dB
#define RDA5802_05_LNA_PORT_SEL             0x00C0  // LNA input port selection bit
    #define RDA5802_05_LNA_PORT_SEL_NO      0x0000  // no input
    #define RDA5802_05_LNA_PORT_SEL_LNAN    0x0040  // LNAN
    #define RDA580X_05_LNA_PORT_SEL_LNAP    0x0080  // LNAP (FMIN on RDA5807_FP)
    #define RDA5802_05_LNA_PORT_SEL_DUAL    0x00C0  // Dual port input
#define RDA5802_05_LNA_ICSEL_BIT            0x0030  // LNA working current bit
    #define RDA5802_05_LNA_ICSEL_BIT_1_8    0x0000  // 1.8mA
    #define RDA5802_05_LNA_ICSEL_BIT_2_1    0x0010  // 2.1mA
    #define RDA5802_05_LNA_ICSEL_BIT_2_5    0x0020  // 2.5mA
    #define RDA5802_05_LNA_ICSEL_BIT_3_0    0x0030  // 3.0mA
#define RDA580X_05_VOLUME                   0x000F  // 4 bits volume (0000 - muted, 1111 - max)

// 06 register
#define RDA5807_06_OPEN_MODE                0x6000  // 2 bits (11) to open read-only regs for writing
#define RDA580X_06_I2S_MODE                 0x1000  // I2S master (0) or slave (1) mode
#define RDA5807_06_SW_LR                    0x0800  // WS relation to l/r channel: ws=0->r,ws=1->l (0) or ws=0->l,ws=1->r (1)
#define RDA5807_06_SCLK_I_EDGE              0x0400  // Normal (0) or inverted (1) sclk
#define RDA5807_06_DATA_SIGNED              0x0200  // Unsigned (0) or signed (1) 16-bit audio data
#define RDA5807_06_WL_I_EDGE                0x0100  // Normal (0) or inverted (1) ws
#define RDA580X_06_I2S_WS_CNT               0x00F0  // I2S WS_STEP selection in master mode
    #define RDA580X_06_I2S_WS_CNT_48        0x0080  // I2S WS_STEP=48 kpbs
    #define RDA580X_06_I2S_WS_CNT_44_1      0x0070  // I2S WS_STEP=44.1 kbps
    #define RDA580X_06_I2S_WS_CNT_32        0x0060  // I2S WS_STEP=32 kbps
    #define RDA580X_06_I2S_WS_CNT_24        0x0050  // I2S WS_STEP=24 kbps
    #define RDA580X_06_I2S_WS_CNT_22_05     0x0040  // I2S WS_STEP=22.05 kbps
    #define RDA580X_06_I2S_WS_CNT_16        0x0030  // I2S WS_STEP=16 kbps
    #define RDA580X_06_I2S_WS_CNT_12        0x0020  // I2S WS_STEP=12 kbps
    #define RDA580X_06_I2S_WS_CNT_11_025    0x0010  // I2S WS_STEP=11.025 kbps
    #define RDA580X_06_I2S_WS_CNT_8         0x0000  // I2S WS_STEP=8 kbps (default)
#define RDA5807_06_WS_O_EDGE                0x0008  // Invert (1) ws output when as master
#define RDA5807_06_SCLK_O_EDGE              0x0004  // Invert (1) sclk output when as master
#define RDA5807_06_L_DELY                   0x0002  // Left channel data delay 1T (1)
#define RDA5807_06_R_DELY                   0x0001  // Right channel data delay 1T (1)

// 07 register
#define RDA5807_07_TH_SOFRBLEND             0x7C00  // 5 bits for noise soft blend, default 10000
#define RDA5807_07_65M_50M_MODE             0x0200  // For BAND=11, 50..76MHz (0)
#define RDA5807_07_SEEK_TH_OLD              0x00FC  // 6 bits seek treshold in old seek mode, valid for SKMODE=1
#define RDA5807_07_SOFTBLEND_EN             0x0002  // Softblend enable (1)
#define RDA5807_07_FREQ_MODE                0x0001  // Manual freq setup (1) for 12,13 regs

// 08 register
#define RDA5807_08_DIRECT_FREQ_HI           0xFF00  // High byte of direct freq offset
#define RDA5807_08_DIRECT_FREQ_LO           0x00FF  // High byte of direct freq offset

// Read mode register values

// 0A register
#define RDA5807_0A_RDSR                     0x8000  // RDS ready (1)
#define RDA580X_0A_STC                      0x4000  // Seek/tune complete (1)
#define RDA580X_0A_SF                       0x2000  // Seek failure (1)
#define RDA5807_0A_RDSS                     0x1000  // RDS decoder synchronized (1)
#define RDA5807_0A_BLK_E                    0x0800  // (When RDS enabled) block E has been found (1)
#define RDA580X_0A_ST                       0x0400  // Stereo indicator (1)
#define RDA580X_0A_READCHAN                 0x03FF  // READCHAN 9..0 bits

// 0B register
#define RDA580X_0B_RSSI                     0xFE00  // 7 bits of RSSI signal level
#define RDA580X_0B_FM_TRUE                  0x0100  // Current channel is a station (1)
#define RDA580X_0B_FM_READY                 0x0080  // Ready
#define RDA5807_0B_ABCD_E                   0x0010  // Data block E (1) or blocks A-D (0)
#define RDA5807_0B_BLERA                    0x000C  // 2 bits error level in block A(RDS) or E(RBDS)
#define RDA5807_0B_BLERB                    0x0003  // 2 bits error level in block B(RDS) or E(RBDS)

// 0C..0F registers
#define RDA5807_0C_RDSA                     0xFFFF
#define RDA5807_0D_RDSA                     0xFFFF
#define RDA5807_0E_RDSA                     0xFFFF
#define RDA5807_0F_RDSA                     0xFFFF

// Some useful definitions

#define RDA5807_CHAN_SPACING		5

#define RDA5807_VOL_MIN				0
#define RDA5807_VOL_MAX				16

#define RDA5807_WR_BYTES			8

#define RDA5807_MIN_FREQ			8700

void rda580xInit(void);

void rda580xSetFreq(uint16_t freq);

void rda580xSetVolume(int8_t value);
void rda580xSetMute(uint8_t value);
void rda580xSetBass(uint8_t value);

void rda580xPowerOn(void);
void rda580xPowerOff(void);

void rda580xUpdateStatus();
uint8_t rda580xIsStereo();
uint8_t rda580xIsStation();
uint8_t rda580xGetLevel();
uint8_t rda580xGetFmReady();
uint8_t rda580xGetSTC();
uint8_t rda580xGetSF();
uint8_t rda580xGetRDSR();
uint16_t rda580xGetFmFreq();

void rda580xSeek(int8_t direction);

#endif // RDA5807X_H
