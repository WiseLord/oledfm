#include "si47xx.h"

// FM/RDS Receiver Command Summary

// Power up device and mode selection.
#define POWER_UP                                0x01
// Returns revision information on the device.
#define GET_REV                                 0x10
// Power down device.
#define POWER_DOWN                              0x11
// Sets the value of a property.
#define SET_PROPERTY                            0x12
// Retrieves a property’s value.
#define GET_PROPERTY                            0x13
// Reads interrupt status bits.
#define GET_INT_STATUS                          0x14
// *Reserved command used for patch file downloads.
#define PATCH_ARGS                              0x15
// *Reserved command used for patch file downloads.
#define PATCH_DATA                              0x16
// Selects the FM tuning frequency.
#define FM_TUNE_FREQ                            0x20
// Begins searching for a valid frequency.
#define FM_SEEK_START                           0x21
// Queries the status of previous FM_TUNE_FREQ or FM_SEEK_START command.
#define FM_TUNE_STATUS                          0x22
// Queries the status of the Received Signal Quality (RSQ) of the current channel.
#define FM_RSQ_STATUS                           0x23
// Returns RDS information for current channel and reads an entry from RDS FIFO.
#define FM_RDS_STATUS                           0x24
// Queries the current AGC settings.
#define FM_AGC_STATUS                           0x27
// Override AGC setting by disabling and forcing it to a fixed value.
#define FM_AGC_OVERRIDE                         0x28
// Configures GPO1, 2, and 3 as output or Hi-Z.
#define GPIO_CTL                                0x80
// Sets GPO1, 2, and 3 output level (low or high).
#define GPIO_SET                                0x81

// FM/RDS Receiver Property Summary

// Enables interrupt sources.
#define GPO_IEN                                 0x0001 // 0x0000
// Configure digital audio outputs.
#define DIGITAL_OUTPUT_FORMAT                   0x0102 // 0x0000
// Configure digital audio output sample rate.
#define DIGITAL_OUTPUT_SAMPLE_RATE              0x0104 // 0x0000
// Sets frequency of reference clock in Hz. The range is 31130 to 34406 Hz, or 0 to disable the AFC. Default is 32768 Hz.
#define REFCLK_FREQ                             0x0201 // 0x8000
// Sets the prescaler value for RCLK input.
#define REFCLK_PRESCALE                         0x0202 // 0x0001
// Sets deemphasis time constant. Default is 75 μs.
#define FM_DEEMPHASIS                           0x1100 // 0x0002
// Selects bandwidth of channel filter applied at the demodulation stage.
#define FM_CHANNEL_FILTER                       0x1102 // 0x0000 or 0x0001
// Sets RSSI threshod for stereo blend
#define FM_BLEND_STEREO_THRESHOLD               0x1105 // 0x0031
// Sets RSSI threshold for mono blend (Full mono below threshold, blend above threshold). To force stereo set this to 0. To force mono set this to 127. Default value is 30 dBμV.
#define FM_BLEND_MONO_THRESHOLD                 0x1106 // 0x001E
// Selects the antenna type and the pin to which it is connected.
#define FM_ANTENNA_INPUT                        0x1107 // 0x0000
// Sets the maximum freq error allowed before setting the AFC rail (AFCRL) indicator. Default value is 20 kHz.
#define FM_MAX_TUNE_ERROR                       0x1108 // 0x001E / 0x0014
// Configures interrupt related to Received Signal Quality metrics.
#define FM_RSQ_INT_SOURCE                       0x1200 // 0x0000
// Sets high threshold for SNR interrupt.
#define FM_RSQ_SNR_HI_THRESHOLD                 0x1201 // 0x007F

// Sets low threshold for SNR interrupt.
#define FM_RSQ_SNR_LO_THRESHOLD                 0x1202 //0x0000
// Sets high threshold for RSSI interrupt.
#define FM_RSQ_RSSI_HI_THRESHOLD                0x1203 //0x007F
// Sets low threshold for RSSI interrupt.
#define FM_RSQ_RSSI_LO_THRESHOLD                0x1204 //0x0000
// Sets high threshold for multipath interrupt.
#define FM_RSQ_MULTIPATH_HI_THRESHOLD           0x1205 //0x007F
// Sets low threshold for multipath interrupt.
#define FM_RSQ_MULTIPATH_LO_THRESHOLD           0x1206 //0x0000
// Sets the blend threshold for blend interrupt when boundary is crossed.
#define FM_RSQ_BLEND_THRESHOLD                  0x1207 //0x0081
// Sets the attack and decay rates when entering and leaving soft mute.
#define FM_SOFT_MUTE_RATE                       0x1300 //0x0040
// Configures attenuation slope during soft mute in dB attenuation per dB SNR below the soft mute SNR threshold. Default value is 2.
#define FM_SOFT_MUTE_SLOPE                      0x1301 //0x0002
// Sets maximum attenuation during soft mute (dB). Set to 0 to disable soft mute. Default is 16 dB.
#define FM_SOFT_MUTE_MAX_ATTENUATION            0x1302 //0x0010
// Sets SNR threshold to engage soft mute. Default is 4 dB.
#define FM_SOFT_MUTE_SNR_THRESHOLD              0x1303 //0x0004
// Sets soft mute release rate. Smaller values provide slower release, and larger values provide faster release. The default is 8192 (approximately 8000 dB/s)
#define FM_SOFT_MUTE_RELEASE_RATE               0x1304 //0x2000
// Sets soft mute attack rate. Smaller values provide slower attack, and larger values provide faster attack. The default is 8192 (approximately 8000 dB/s)
#define FM_SOFT_MUTE_ATTACK_RATE                0x1305 // 0x2000
// Sets the bottom of the FM band for seek. Default is 8750 (87.5 MHz).
#define FM_SEEK_BAND_BOTTOM                     0x1400 // 0x222E
// Sets the top of the FM band for seek. Default is 10790 (107.9 MHz).
#define FM_SEEK_BAND_TOP                        0x1401 // 0x2A26
// Selects frequency spacing for FM seek. Default value is 10 (100 kHz).
#define FM_SEEK_FREQ_SPACING                    0x1402 // 0x000A
// Sets the SNR threshold for a valid FM Seek/Tune. Default value is 3 dB.
#define FM_SEEK_TUNE_SNR_THRESHOLD              0x1403 // 0x0003
// Sets the RSSI threshold for a valid FM Seek/Tune. Default value is 20 dBμV.
#define FM_SEEK_TUNE_RSSI_TRESHOLD              0x1404 // 0x0014
// Configures RDS interrupt behavior.
#define FM_RDS_INT_SOURCE                       0x1500 // 0x0000
// Sets the minimum number of RDS groups stored in the receive FIFO required before RDSRECV is set.
#define FM_RDS_INT_FIFO_COUNT                   0x1501 // 0x0000
// Configures RDS setting.
#define FM_RDS_CONFIG                           0x1502 // 0x0000
// Sets the confidence level threshold for each RDS block.
#define FM_RDS_CONFIDENCE                       0x1503 // 0x1111
// Sets the AGC attack rate. Larger values provide slower attack and smaller values provide faster attack. The default is 4 (approximately 1500 dB/s).
#define FM_AGC_ATTACK_RATE                      0x1700 // 0x0004
// Sets the AGC release rate. Larger values provide slower release and smaller values provide faster release. The default is 140 (approximately 43 dB/s).
#define FM_AGC_RELEASE_RATE                     0x1701 // 0x008C
// Sets RSSI threshold for stereo blend. (Full stereo above threshold, blend below threshold.) To force stereo, set this to 0. To force mono, set this to 127. Default value is 49 dBμV.
#define FM_BLEND_RSSI_STEREO_THRESHOLD          0x1800 // 0x0031
// Sets RSSI threshold for mono blend (Full mono below threshold, blend above threshold). To force stereo, set this to 0. To force mono, set this to 127. Default value is 30 dBμV.
#define FM_BLEND_RSSI_MONO_THRESHOLD            0x1801 // 0x001E
//Sets the stereo to mono attack rate for RSSI based blend. Smaller values provide slower attack and larger values provide faster attack. The default is 4000 (approximately 16 ms).
#define FM_BLEND_RSSI_ATTACK_RATE               0x1802 // 0x0FA0
// Sets the mono to stereo release rate for RSSI based blend. Smaller values provide slower release and larger values provide faster release. The default is 400 (approximately 164 ms).
#define FM_BLEND_RSSI_RELEASE_RATE              0x1803 // 0x0190
// Sets SNR threshold for stereo blend (Full stereo above threshold, blend below threshold). To force stereo, set this to 0. To force mono, set this to 127. Default value is 27 dB.
#define FM_BLEND_SNR_STEREO_THRESHOLD           0x1804 // 0x001B
// Sets SNR threshold for mono blend (Full mono below threshold, blend above threshold). To force stereo, set this to 0. To force mono, set this to 127. Default value is 14 dB.
#define FM_BLEND_SNR_MONO_THRESHOLD             0x1805 // 0x000E
// Sets the stereo to mono attack rate for SNR based blend. Smaller values provide slower attack and larger values provide faster attack. The default is 4000 (approximately 16 ms).
#define FM_BLEND_SNR_ATTACK_RATE                0x1806 // 0x0FA0
// Sets the mono to stereo release rate for SNR based blend. Smaller values provide slower release and larger values provide faster release. The default is 400 (approximately 164 ms).
#define FM_BLEND_SNR_RELEASE_RATE               0x1807 // 0x0190
// Sets multipath threshold for stereo blend (Full stereo below threshold, blend above threshold). To force stereo, set this to 100. To force mono, set this to 0. Default value is 20.
#define FM_BLEND_MULTIPATH_STEREO_THRESHOLD     0x1808 // 0x0014
// Sets Multipath threshold for mono blend (Full mono above threshold, blend below threshold). To force stereo, set to 100. To force mono, set to 0. The default is 60.
#define FM_BLEND_MULTIPATH_MONO_THRESHOLD       0x1809 // 0x003C
// Sets the stereo to mono attack rate for Multipath based blend. Smaller values provide slower attack and larger values provide faster attack. The default is 4000 (approximately 16 ms).
#define FM_BLEND_MULTIPATH_ATTACK_RATE          0x180A // 0x0FA0
// Sets the mono to stereo release rate for Multipath based blend. Smaller values provide slower release and larger values provide faster release. The default is 40 (approximately 1.64 s).
#define FM_BLEND_MULTIPATH_RELEASE_RATE         0x180B // 0x0028
// Sets the maximum amount of stereo separation
#define FM_BLEND_MAX_STEREO_SEPARATION          0x180C // 0x0000
// Sets the threshold for detecting impulses in dB above the noise floor. Default value is 16.
#define FM_NB_DETECT_THRESHOLD                  0x1900 // 0x0010
// Interval in micro-seconds that original samples are replaced by interpolated clean samples. Default value is 24 μs.
#define FM_NB_INTERVAL                          0x1901 // 0x0018
// Noise blanking rate in 100 Hz units. Default value is 64.
#define FM_NB_RATE                              0x1902 // 0x0040
// Sets the bandwidth of the noise floor estimator Default value is 300.
#define FM_NB_IIR_FILTER                        0x1903 // 0x012C
// Delay in micro-seconds before applying impulse blanking to the original samples. Default value is 133.
#define FM_NB_DELAY                             0x1904 // 0x00AA
// Sets the SNR level at which hi-cut begins to band limit. Default value is 24.
#define FM_HICUT_SNR_HIGH_THRESHOLD             0x1A00 // 0x0018
// Sets the SNR level at which hi-cut reaches maximum band limiting. Default value is 15.
#define FM_HICUT_SNR_LOW_THRESHOLD              0x1A01 // 0x000F
// Sets the rate at which hi-cut lowers the cut-off frequency. Default value is 20000 (approximately 3 ms)
#define FM_HICUT_ATTACK_RATE                    0x1A02 // 0x4E20
// Sets the rate at which hi-cut increases the cut-off frequency. Default value is 20. (approximately 3.3 s)
#define FM_HICUT_RELEASE_RATE                   0x1A03 // 0x0014
// Sets the MULTIPATH level at which hi-cut begins to band limit. Default value is 20.
#define FM_HICUT_MULTIPATH_TRIGGER_THRESHOLD    0x1A04 // 0x0014
// Sets the MULTIPATH level at which hi-cut reaches maximum band limiting. Default value is 60.
#define FM_HICUT_MULTIPATH_END_THRESHOLD        0x1A05 // 0x003C
// Sets the maximum band limit frequency for hi-cut and also sets the maximum audio frequency. Default value is 0 (disabled).
#define FM_HICUT_CUTOFF_FREQUENCY               0x1A06 // 0x0000
// Sets the output volume.
#define RX_VOLUME                               0x4000 // 0x003F
// Mutes the audio output. L and R audio outputs may be muted independently.
#define RX_HARD_MUTE                            0x4001 // 0x0000

// Status Response for the FM/RDS Receiver
#define CTS                                     (1<<7) // 0 = Wait before sending next command. 1 = Clear to send next command.
#define ERR                                     (1<<6) // 0 = No error. 1 = Error
#define RSQINT                                  (1<<3) // 0 = Received Signal Quality measurement has not been triggered. 1 = Received Signal Quality measurement has been triggered.
#define RDSINT                                  (1<<2) // 0 = Radio data system interrupt has not been triggered. 1 = Radio data system interrupt has been triggered.
#define STCINT                                  (1<<0) // 0 = Tune complete has not been triggered. 1 = Tune complete has been triggered.
