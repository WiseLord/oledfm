#ifndef PINS_H
#define PINS_H

#include <avr/io.h>
#include "arduinopromini.h"

#define CONCAT(x,y)         x ## y

#define DDR(x)              CONCAT(DDR,x)
#define PORT(x)             CONCAT(PORT,x)
#define PIN(x)              CONCAT(PIN,x)

#define OUT(x)              DDR(x) |= x ## _LINE
#define IN(x)               DDR(x) &= ~x ## _LINE
#define SET(x)              PORT(x) |= x ## _LINE
#define CLR(x)              PORT(x) &= ~x ## _LINE

// Buttons
#define BUTTON_0            ARDUINO_D4
#define BUTTON_0_LINE       ARDUINO_D4_LINE
#define BUTTON_1            ARDUINO_D5
#define BUTTON_1_LINE       ARDUINO_D5_LINE
#define BUTTON_2            ARDUINO_D6
#define BUTTON_2_LINE       ARDUINO_D6_LINE
#define PCINT_BUTTON0       PCINT20
#define PCINT_BUTTON1       PCINT21
#define PCINT_BUTTON2       PCINT22

// LED
#define LED_RED             ARDUINO_D13
#define LED_RED_LINE        ARDUINO_D13_LINE

/* ST7920 port*/
#define SSD1306_SCK			ARDUINO_A0
#define SSD1306_SCK_LINE	ARDUINO_A0_LINE
#define SSD1306_SDA			ARDUINO_A1
#define SSD1306_SDA_LINE	ARDUINO_A1_LINE



#define SI470X_B_SDIO       ARDUINO_SDA
#define SI470X_B_SDIO_LINE  ARDUINO_SDA_LINE
#define SI470X_B_SCLK       ARDUINO_SCL
#define SI470X_B_SCLK_LINE  ARDUINO_SCL_LINE
#define SI470X_B_SEN        ARDUINO_D9
#define SI470X_B_SEN_LINE   ARDUINO_D9_LINE
#define SI470X_B_RST        ARDUINO_D8
#define SI470X_B_RST_LINE   ARDUINO_D8_LINE
#define SI470X_B_GPIO1      ARDUINO_D3
#define SI470X_B_GPIO1_LINE ARDUINO_D2_LINE
#define SI470X_B_GPIO2      ARDUINO_D3
#define SI470X_B_GPIO2_LINE ARDUINO_D2_LINE

#endif // PINS_H
