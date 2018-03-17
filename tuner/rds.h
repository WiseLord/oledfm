#ifndef RDS_H
#define RDS_H

#include <inttypes.h>

typedef union {
    struct {
        uint16_t B1;
        uint16_t B2;
        uint16_t B3;
        uint16_t B4;
    };
    struct {
        uint8_t B1L;
        uint8_t B1H;
        uint8_t B2L;
        uint8_t B2H;
        uint8_t B3L;
        uint8_t B3H;
        uint8_t B4L;
        uint8_t B4H;
    };
} RdsRaw_t;

typedef enum {
    PTY_None,
    PTY_News,
    PTY_CurrentAffairs,
    PTY_Information,
    PTY_Sport,
    PTY_Education,
    PTY_Drama,
    PTY_Culture,
    PTY_Science,
    PTY_Varied,
    PTY_PopMusic,
    PTY_RockMusick,
    PTY_EasyListening,
    PTY_LightClassics,
    PTY_SeriousClassics,
    PTY_OtherMusic,

    PTY_END
} RdsPty_t;

typedef struct {
    RdsPty_t pty;
    char ps[9];
    char text[17];
} RdsData_t;

extern RdsRaw_t rdsRaw;
extern RdsData_t rdsData;

#define GROUP_0     0x0000
#define GROUP_2A    0x2000
#define GROUP_15B   0xF800

void rdsDecode();
void rdsClear();

#endif // RDS_H
