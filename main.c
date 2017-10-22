#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "ssd1306.h"
#include "glcd.h"
#include "fonts.h"
#include "screen.h"
#include "input.h"
#include "i2c.h"
#include "rda580x.h"

#include <util/delay.h>
#include "pins.h"

void hwInit()
{
    glcdInit();
    inputInit();
    screenInit();
    I2CInit();

    // Setup sleep mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    PCMSK2 |= (BUTTON_1_LINE | BUTTON_2_LINE | BUTTON_3_LINE);

    // Interrupts
    TIMSK0 |= (1 << OCIE0A);    // Input timer compare
    sei();

    rda580xInit();
    rda580xSetVolume(3);
    rda580xPowerOn();
    rda580xSetFreq(9950);
}

void sleep(void)
{
    // Prepare sleep
//    glcdSleep();
    TIMSK0 &= ~(1 << OCIE0A);   // Input timer compare disable
    PCICR |= (1<<PCIE2);        // Buttons interrupt enable

    // Sleep
    sleep_mode();

    // Wakeup
    PCICR &= ~(1<<PCIE2);       // Buttons interrupt disable
    TIMSK0 |= (1 << OCIE0A);    // Input timer compare enable
//    glcdInit();
}

int main(void)
{
    OUT(LED_RED);

    hwInit();
    screenShowMain(CLEAR_ALL);

    while (1) {
        Screen screen = screenGet();
        uint8_t btnCmd = getBtnCmd();

        if (measureGetSleepTimer() == 0) {
            btnCmd = BTN_STATE_0;
            sleep();
        }

        if (btnCmd)
            measureResetSleepTimer();

        switch (btnCmd) {
        case BTN_0:
            switch (screen) {
            case SCREEN_MAIN:
                break;
            case SCREEN_SETUP:
                break;
            default:
                break;
            }
            break;
        case BTN_1:
            SET(LED_RED);
            switch (screen) {
            case SCREEN_MAIN:
                screenShowSetup(CLEAR_ALL);
                break;
            case SCREEN_SETUP:
                screenShowMain(CLEAR_ALL);
                break;
            default:
                break;
            }
            break;
        case BTN_2:
            CLR(LED_RED);
            switch (screen) {
            case SCREEN_MAIN:
                break;
            case SCREEN_SETUP:
                break;
            default:
                break;
            }
            break;
        case BTN_0_LONG:
            switch (screen) {
            case SCREEN_MAIN:
                break;
            case SCREEN_SETUP:
                break;
            default:
                break;
            }
            break;
        case BTN_1_LONG:
            switch (screen) {
            case SCREEN_MAIN:
                break;
            case SCREEN_SETUP:
                break;
            default:
                break;
            }
            break;
        case BTN_2_LONG:
            switch (screen) {
            case SCREEN_MAIN:
                break;
            case SCREEN_SETUP:
                break;
            default:
                break;
            }
            break;
        case BTN_1_LONG | BTN_2_LONG:
            switch (screen) {
            default:
                break;
            }
            break;
        default:
            break;
        }
        screenUpdate();
    }

    return 0;
}
