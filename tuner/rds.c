#include "rds.h"
#include "string.h"

RdsRaw_t rdsRaw;
RdsData_t rdsData;

#define CHAR_OK(x) ((x) >= 0x20 && (x) <= 0x80)

void rdsDecode()
{
    uint16_t group;
    uint8_t index;
    uint8_t ch;

    group = rdsRaw.B2 & 0xF800;

    switch (group) {
    case GROUP_0:
    case GROUP_15B:
        index = rdsRaw.B2L & 0x03;

        ch = rdsRaw.B4H;
        if (CHAR_OK(ch))
            rdsData.ps[2 * index] = ch;

        ch = rdsRaw.B4L;
        if (CHAR_OK(ch))
            rdsData.ps[2 * index + 1] = ch;

        break;
    case GROUP_2A:
        index = rdsRaw.B2L & 0x03; // 0x0F really, but will limit 16 chars

        ch = rdsRaw.B3H;
        if (CHAR_OK(ch))
            rdsData.text[4 * index] = ch;
        ch = rdsRaw.B3L;
        if (CHAR_OK(ch))
            rdsData.text[4 * index + 1] = ch;
        ch = rdsRaw.B4H;
        if (CHAR_OK(ch))
            rdsData.text[4 * index + 2] = ch;
        ch = rdsRaw.B4L;
        if (CHAR_OK(ch))
            rdsData.text[4 * index + 3] = ch;

        break;
    default:
        break;
    }
}

void rdsClear()
{
    memset(&rdsData, 0, sizeof(RdsData_t));
    memset(&rdsData.ps, ' ', 8);
    memset(&rdsData.text, '-', 16);
}
