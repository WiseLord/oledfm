#include "input.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "pins.h"

static volatile uint8_t btnCmd = 0;         // Command buffer
static volatile uint16_t sleepTimer = SLEEP_TIMER;

void inputInit(void)
{
    // Buttons as inputs
    IN(BUTTON_1);
    IN(BUTTON_2);
    IN(BUTTON_3);
    // Enable pull-up resistors
    SET(BUTTON_1);
    SET(BUTTON_2);
    SET(BUTTON_3);

    TCCR0A = (1 << WGM01);                  // CTC mode
    TCCR0B = (1 << CS02) | (1 << CS00);     // PSK = 1024
    OCR0A = 124;                            // 16M/(OCR0A - 1)/PSK = 125 Hz
}

ISR(TIMER0_COMPA_vect, ISR_NOBLOCK)        // TIME_STEP_FREQ = 125 Hz
{
    static uint8_t btnCnt = 0;              // Buttons press duration
    static uint8_t btnPrev = BTN_STATE_0;   // Previous buttons state

    uint8_t btnNow = BTN_STATE_0;

    if (~PIN(BUTTON_1) & BUTTON_1_LINE)
        btnNow |= BTN_0;
    if (~PIN(BUTTON_2) & BUTTON_2_LINE)
        btnNow |= BTN_1;
    if (~PIN(BUTTON_3) & BUTTON_3_LINE)
        btnNow |= BTN_2;

    // If button event has happened, place it to command buffer
    if (btnNow) {
        if (btnNow == btnPrev) {
            btnCnt++;
            if (btnCnt == LONG_PRESS) {
                btnCmd = (btnPrev << 4);
                btnCnt = LONG_PRESS - AUTOREPEAT;
            }
        } else {
            btnPrev = btnNow;
        }
    } else {
        if ((btnCnt > SHORT_PRESS) && (btnCnt < LONG_PRESS - AUTOREPEAT))
            btnCmd = btnPrev;
        btnCnt = 0;
    }

    if (sleepTimer)
        sleepTimer--;
}

ISR (PCINT2_vect) {
    sleepTimer = SLEEP_TIMER;
}

uint8_t getBtnCmd()
{
    uint8_t ret = btnCmd;
    btnCmd = BTN_STATE_0;

    return ret;
}

uint16_t measureGetSleepTimer(void)
{
    return sleepTimer;
}

void measureResetSleepTimer()
{
    sleepTimer = SLEEP_TIMER;
}
