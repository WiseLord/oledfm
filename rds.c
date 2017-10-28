#include "rds.h"
#include "tuner.h"
#include "eeprom.h"

static char psText[9] = "        ";

void rdsDecode()
{
    uint8_t group = (Tuner.RDS_B & 0xF000) >> 12;
    uint8_t index = (Tuner.RDS_B & 0x0003);

    uint8_t i;
    uint8_t rdsChar;

    if (group == 0) {
        for (i = 0; i < 2; i++) {
            rdsChar = (Tuner.RDS_D >> (i ? 0 : 8)) & 0xFF;
            if (rdsChar >= 0x20 && rdsChar <= 0x80)
                psText[2 * index + i] = rdsChar;
        }
    }
}

char *rdsPsText(void)
{
	return psText;
}
