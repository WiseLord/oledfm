#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "ssd1306.h"
#include "glcd.h"
#include "fonts.h"
#include "screen.h"
#include "input.h"
#include "i2c.h"
#include "tuner.h"

#include <util/delay.h>
#include "pins.h"
#include "eeprom.h"

void hwInit()
{
    glcdInit();
    inputInit();
    screenInit();
    I2CInit();

    // Setup sleep mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    // Interrupts
    TIMSK0 |= (1 << OCIE0A);    // Input timer compare
    sei();

    tunerInit(TUNER_RDA5807);

    OUT(LED_RED);
}

void sleep(void)
{
    // Prepare sleep
    TIMSK0 &= ~(1 << OCIE0A);   // Input timer compare disable

    PCMSK2 = BUTTON_0_LINE | BUTTON_1_LINE | BUTTON_2_LINE;
    if (Screen == SCREEN_STANDBY)
        PCMSK2 = BUTTON_0_LINE;
    PCICR |= (1<<PCIE2);        // Buttons interrupt enable

    SET(LED_RED);
    glcdSleep();
    // Sleep
    sleep_mode();
    glcdWakeup();
    CLR(LED_RED);

    // Wakeup
    PCICR &= ~(1<<PCIE2);       // Buttons interrupt disable
    TIMSK0 |= (1 << OCIE0A);    // Input timer compare enable
}

int main(void)
{
    hwInit();
    screenSet(SCREEN_STANDBY);
    screenUpdate();
    timerSleepSet(SLEEP_TIMER_STANDBY);

    while (1) {
        uint8_t btnCmd = getBtnCmd();

        if (timerSleepGet() == 0) {
            sleep();
        }

        if (btnCmd) {
            if (Screen == SCREEN_STANDBY)
                timerSleepSet(SLEEP_TIMER_STANDBY);
            else
                timerSleepSet(SLEEP_TIMER_WORK);
        }

        switch (btnCmd) {
        case BTN_0:
            switch (Screen) {
            default:
                break;
            }
            break;
        case BTN_1:
            switch (Screen) {
            case SCREEN_MAIN:
                tunerSeek(-1);
                break;
            default:
                break;
            }
            break;
        case BTN_2:
            switch (Screen) {
            case SCREEN_MAIN:
                tunerSeek(+1);
                break;
            default:
                break;
            }
            break;
        case BTN_0_LONG:
            switch (Screen) {
            case SCREEN_STANDBY:
                eepRestoreTuner();
                tunerSetPower(1);
                tunerSetFreq(Tuner.eep.freq);
                tunerSetVolume(Tuner.eep.volume);
                screenSet(SCREEN_MAIN);
                timerSleepSet(SLEEP_TIMER_WORK);
                break;
            case SCREEN_MAIN:
                eepSaveTuner();
                tunerSetPower(0);
                screenSet(SCREEN_STANDBY);
                timerSleepSet(SLEEP_TIMER_STANDBY);
                break;
            default:
                break;
            }
            break;
        case BTN_1_LONG:
            switch (Screen) {
            case SCREEN_MAIN:
                tunerSetVolume(Tuner.eep.volume - 1);
                break;
            default:
                break;
            }
            break;
        case BTN_2_LONG:
            switch (Screen) {
            case SCREEN_MAIN:
                tunerSetVolume(Tuner.eep.volume + 1);
                break;
            default:
                break;
            }
            break;
        case BTN_1_LONG | BTN_2_LONG:
            switch (Screen) {
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
