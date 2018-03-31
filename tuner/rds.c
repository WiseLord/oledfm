#include "rds.h"

static char rdsPS[9];
static uint8_t rdsFlag = 0;

typedef union {
    struct {
        uint16_t blkA;
        uint16_t blkB;
        uint16_t blkC;
        uint16_t blkD;
    };
    uint16_t blk[4];
} RdsBlocks_t;

RdsBlocks_t rdsBlocks;

#define CHAR_OK(x) ((x) >= 0x20 && (x) <= 0x80)

char *rdsGetText()
{
    return rdsPS;
}

void rdsDecode(uint8_t *data)
{
    char ch;

    uint16_t group;
    uint8_t index;

    // Read byte array, converting BE to LE
    for (uint8_t i = 0; i < 4; i++) {
        uint16_t blk;
        blk  = *(data++) << 8;
        blk |= *(data++);
        rdsBlocks.blk[i] = blk;
    }
    group   = rdsBlocks.blkB & 0xF800;

    switch (group) {
    case GROUP_0:
    case GROUP_15B:
        index   = rdsBlocks.blkB & 0x0003;

        ch = (rdsBlocks.blkD & 0xFF00) >> 8;
        if (CHAR_OK(ch))
            rdsPS[2 * index] = ch;

        ch = (rdsBlocks.blkD & 0x00FF) >> 0;
        if (CHAR_OK(ch))
            rdsPS[2 * index + 1] = ch;

        rdsFlag = RDS_FLAG_INIT;
        break;
    default:
        break;
    }
}

void rdsDisable()
{
    uint8_t i;

    for (i = 0; i < 8; i++)
        rdsPS[i] = ' ';

    rdsFlag = 0;
}

uint8_t rdsGetFlag()
{
    if (rdsFlag)
        rdsFlag--;

    return rdsFlag;
}
