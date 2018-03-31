#ifndef RDS_H
#define RDS_H

#include <inttypes.h>

#define GROUP_0     0x0000
#define GROUP_2A    0x2000
#define GROUP_15B   0xF800

#define RDS_FLAG_INIT   50

char *rdsGetText();
void rdsSetBlocks(uint8_t *rdsBlock);
void rdsDecode(uint8_t *data);
void rdsDisable();
uint8_t rdsGetFlag();

#endif // RDS_H
