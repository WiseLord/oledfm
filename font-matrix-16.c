#include <avr/pgmspace.h>

const uint8_t font_matrix_16[] PROGMEM = {

    0x02,   // font height in bytes
    0x7F,   // position of symbol-space between letters
    0xE0,   // count of chars
    0x20,   // ascii char offset
    0x40,   // non-ascii char offset

    // Chars widths
    0x0A, 0x04, 0x07, 0x0A, 0x0A, 0x0A, 0x09, 0x03,
    0x05, 0x05, 0x08, 0x08, 0x03, 0x08, 0x03, 0x08,                     // 0x20..0x2F
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x03, 0x03, 0x08, 0x08, 0x08, 0x0A,                     // 0x30..0x3F
    0x0B, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x06, 0x0A, 0x0A, 0x09, 0x0A, 0x0A, 0x0A,                     // 0x40..0x4F
    0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x0A, 0x09, 0x0B,
    0x0A, 0x0A, 0x0A, 0x04, 0x08, 0x04, 0x0B, 0x0A,                     // 0x50..0x5F
    0x03, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x09,
    0x09, 0x06, 0x06, 0x08, 0x06, 0x0A, 0x09, 0x09,                     // 0x60..0x6F
    0x09, 0x09, 0x08, 0x08, 0x08, 0x09, 0x09, 0x0A,
    0x09, 0x09, 0x09, 0x06, 0x02, 0x06, 0x0A, 0x02,                     // 0x70..0x7F

    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,                     // 0x80..0x8F
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,                     // 0x90..0x9F
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x0A, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,                     // 0xA0..0xAF
    0x07, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x09, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,                     // 0xB0..0xBF
    0x0A, 0x0A, 0x0A, 0x09, 0x0B, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,                     // 0xC0..0xCF
    0x0A, 0x0A, 0x08, 0x0A, 0x0A, 0x0A, 0x0B, 0x0A,
    0x0A, 0x0B, 0x0B, 0x0B, 0x09, 0x0A, 0x0B, 0x0A,                     // 0xD0..0xDF
    0x09, 0x09, 0x09, 0x08, 0x0A, 0x09, 0x0A, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x0A, 0x08, 0x09, 0x09,                     // 0xE0..0xEF
    0x09, 0x09, 0x08, 0x09, 0x0A, 0x09, 0x09, 0x08,
    0x0A, 0x0B, 0x0A, 0x0A, 0x08, 0x09, 0x0A, 0x09,                     // 0xF0..0xFF

    // Chars data
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // 0x20 =>

    0xF8, 0xFE, 0xFE, 0xF8,
    0x00, 0x67, 0x67, 0x00,                                             // 0x21 => !

    0x0F, 0x07, 0x03, 0x00, 0x0F, 0x07, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                           // 0x22 => "

    0x30, 0x30, 0xFE, 0xFE, 0x30, 0x30, 0xFE, 0xFE, 0x30, 0x30,
    0x0C, 0x0C, 0x7F, 0x7F, 0x0C, 0x0C, 0x7F, 0x7F, 0x0C, 0x0C,         // 0x23 => #

    0x78, 0xFC, 0xCE, 0x86, 0xFF, 0xFF, 0x86, 0x8E, 0x1C, 0x18,
    0x18, 0x38, 0x71, 0x61, 0xFF, 0xFF, 0x61, 0x73, 0x3F, 0x1E,         // 0x24 => $

    0x0C, 0x12, 0x12, 0x0C, 0x80, 0xE0, 0x78, 0x1E, 0x06, 0x00,
    0x00, 0x60, 0x78, 0x1E, 0x07, 0x01, 0x30, 0x48, 0x48, 0x30,         // 0x25 => %

    0x00, 0x70, 0xFC, 0x8E, 0xC6, 0x7C, 0x38, 0x00, 0x00,
    0x3E, 0x7F, 0x63, 0x43, 0x6F, 0x3C, 0x38, 0x6C, 0x44,               // 0x26 => &

    0x0F, 0x07, 0x03,
    0x00, 0x00, 0x00,                                                   // 0x27 => '

    0xF0, 0xFC, 0x1E, 0x07, 0x03,
    0x0F, 0x3F, 0x78, 0xE0, 0xC0,                                       // 0x28 => (

    0x03, 0x07, 0x1E, 0xFC, 0xF0,
    0xC0, 0xE0, 0x78, 0x3F, 0x0F,                                       // 0x29 => )

    0xC0, 0xC0, 0x80, 0xF0, 0xF0, 0x80, 0xC0, 0xC0,
    0x00, 0x0C, 0x0F, 0x03, 0x03, 0x0F, 0x0C, 0x00,                     // 0x2A => *

    0x80, 0x80, 0x80, 0xF0, 0xF0, 0x80, 0x80, 0x80,
    0x01, 0x01, 0x01, 0x0F, 0x0F, 0x01, 0x01, 0x01,                     // 0x2B => +

    0x00, 0x00, 0x00,
    0xF0, 0x70, 0x30,                                                   // 0x2C => ,

    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,                     // 0x2D => -

    0x00, 0x00, 0x00,
    0x70, 0x70, 0x70,                                                   // 0x2E => .

    0x00, 0x00, 0x00, 0x80, 0xE0, 0x78, 0x1E, 0x06,
    0x60, 0x78, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00,                     // 0x2F => /

    0xF8, 0xFC, 0x0E, 0x06, 0x86, 0x86, 0xC6, 0xCE, 0xFC, 0xF8,
    0x1F, 0x3F, 0x73, 0x63, 0x61, 0x61, 0x60, 0x70, 0x3F, 0x1F,         // 0x30 => 0

    0x00, 0x18, 0x18, 0x1C, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x00,         // 0x31 => 1

    0x18, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0x78,
    0x70, 0x78, 0x7C, 0x6E, 0x66, 0x63, 0x63, 0x61, 0x61, 0x60,         // 0x32 => 2

    0x18, 0x1C, 0x0E, 0x86, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78,
    0x18, 0x38, 0x70, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0x33 => 3

    0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0xFE, 0xFE, 0x00, 0x00,
    0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x7F, 0x7F, 0x06, 0x06,         // 0x34 => 4

    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x86, 0x06,
    0x18, 0x38, 0x70, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,         // 0x35 => 5

    0xF8, 0xFC, 0x8E, 0xC6, 0xC6, 0xC6, 0xC6, 0xCE, 0x8C, 0x0C,
    0x1F, 0x3F, 0x71, 0x61, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,         // 0x36 => 6

    0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0xE6, 0x7E, 0x1E, 0x06,
    0x00, 0x00, 0x60, 0x78, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00,         // 0x37 => 7

    0x00, 0x78, 0xFC, 0xCE, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x00,
    0x1E, 0x3F, 0x73, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0x38 => 8

    0xF8, 0xFC, 0x8E, 0x06, 0x06, 0x06, 0x86, 0x8E, 0xFC, 0xF8,
    0x18, 0x39, 0x73, 0x63, 0x63, 0x63, 0x63, 0x71, 0x3F, 0x1F,         // 0x39 => 9

    0x1C, 0x1C, 0x1C,
    0x38, 0x38, 0x38,                                                   // 0x3A => :

    0x1C, 0x1C, 0x1C,
    0xB8, 0xF8, 0x78,                                                   // 0x3B => ;

    0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06,
    0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0x60,                     // 0x3C => <

    0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,                     // 0x3D => =

    0x06, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80,
    0x60, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01,                     // 0x3E => >

    0x38, 0x3C, 0x0E, 0x06, 0x06, 0x06, 0x86, 0xCE, 0xFC, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x6E, 0x6F, 0x03, 0x01, 0x00, 0x00,         // 0x3F => ?

    0xF8, 0xFC, 0x0E, 0xE6, 0xF6, 0x36, 0xF6, 0xF6, 0x06, 0xFC, 0xF8,
    0x1F, 0x3F, 0x70, 0x67, 0x6F, 0x6C, 0x6F, 0x6F, 0x6C, 0x27, 0x03,   // 0x40 => @

    0xF0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0,
    0x7F, 0x7F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x7F, 0x7F,         // 0x41 => A

    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x00,
    0x7F, 0x7F, 0x61, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0x42 => B

    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0x18,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x18,         // 0x43 => C

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,         // 0x44 => D

    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x06,
    0x7F, 0x7F, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x60,         // 0x45 => E

    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x06,
    0x7F, 0x7F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,         // 0x46 => F

    0xF0, 0xFC, 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x0C,
    0x0F, 0x3F, 0x78, 0x60, 0x60, 0x63, 0x63, 0x63, 0x7F, 0x3F,         // 0x47 => G

    0xFE, 0xFE, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE,
    0x7F, 0x7F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7F, 0x7F,         // 0x48 => H

    0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06,
    0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60,                                 // 0x49 => I

    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0xFE, 0xFE,
    0x18, 0x38, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,         // 0x4A => J

    0xFE, 0xFE, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06,
    0x7F, 0x7F, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0x60,         // 0x4B => K

    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,               // 0x4C => L

    0xFE, 0xFE, 0x3C, 0xF0, 0xC0, 0xC0, 0xF0, 0x3C, 0xFE, 0xFE,
    0x7F, 0x7F, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x7F, 0x7F,         // 0x4D => M

    0xFE, 0xFE, 0x1C, 0x70, 0xE0, 0x80, 0x00, 0x00, 0xFE, 0xFE,
    0x7F, 0x7F, 0x00, 0x00, 0x01, 0x07, 0x0E, 0x38, 0x7F, 0x7F,         // 0x4E => N

    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,         // 0x4F => O

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0xF8,
    0x7F, 0x7F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00,         // 0x50 => P

    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x6C, 0x7C, 0x38, 0x7F, 0x6F,         // 0x51 => Q

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0xF8,
    0x7F, 0x7F, 0x03, 0x03, 0x07, 0x0F, 0x1F, 0x3B, 0x71, 0x60,         // 0x52 => R

    0x78, 0xFC, 0xCE, 0x86, 0x86, 0x86, 0x86, 0x8E, 0x1C, 0x18,
    0x18, 0x38, 0x71, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0x53 => S

    0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06,
    0x00, 0x00, 0x00, 0x7F, 0x7F, 0x00, 0x00, 0x00,                     // 0x54 => T

    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,         // 0x55 => U

    0x0E, 0x7E, 0xF0, 0x80, 0x00, 0x80, 0xF0, 0x7E, 0x0E,
    0x00, 0x00, 0x03, 0x1F, 0x7C, 0x1F, 0x03, 0x00, 0x00,               // 0x56 => V

    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFE, 0xFE,
    0x0F, 0x3F, 0x78, 0x1C, 0x0E, 0x07, 0x0E, 0x1C, 0x78, 0x3F, 0x0F,   // 0x57 => W

    0x06, 0x1E, 0x38, 0x60, 0xC0, 0xC0, 0x60, 0x38, 0x1E, 0x06,
    0x60, 0x78, 0x1C, 0x06, 0x03, 0x03, 0x06, 0x1C, 0x78, 0x60,         // 0x58 => X

    0x06, 0x1E, 0x78, 0xE0, 0x80, 0x80, 0xE0, 0x78, 0x1E, 0x06,
    0x00, 0x00, 0x00, 0x01, 0x7F, 0x7F, 0x01, 0x00, 0x00, 0x00,         // 0x59 => Y

    0x06, 0x06, 0x06, 0x06, 0x86, 0xC6, 0x66, 0x3E, 0x1E, 0x06,
    0x60, 0x78, 0x7C, 0x66, 0x63, 0x61, 0x60, 0x60, 0x60, 0x60,         // 0x5A => Z

    0xFF, 0xFF, 0x03, 0x03,
    0xFF, 0xFF, 0xC0, 0xC0,                                             // 0x5B => [

    0x06, 0x1E, 0x78, 0xE0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x07, 0x1E, 0x78, 0x60,                     // 0x5C => <SLASH>

    0x03, 0x03, 0xFF, 0xFF,
    0xC0, 0xC0, 0xFF, 0xFF,                                             // 0x5D => ]

    0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x5E => ^

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,         // 0x5F => _

    0x03, 0x07, 0x0F,
    0x00, 0x00, 0x00,                                                   // 0x60 => `

    0x00, 0x40, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0,
    0x38, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7F, 0x7F,               // 0x61 => a

    0xFE, 0xFE, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,               // 0x62 => b

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xC0, 0x80,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x30, 0x10,               // 0x63 => c

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xC0, 0xFE, 0xFE,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x7F, 0x7F,               // 0x64 => d

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xC0, 0x80,
    0x1F, 0x3F, 0x76, 0x66, 0x66, 0x66, 0x66, 0x27, 0x03,               // 0x65 => e

    0x80, 0x80, 0xF8, 0xFC, 0x8E, 0x86, 0x86, 0x06,
    0x01, 0x01, 0x7F, 0x7F, 0x01, 0x01, 0x01, 0x00,                     // 0x66 => f

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0,
    0x03, 0xC7, 0xCE, 0xCC, 0xCC, 0xCC, 0xE6, 0x7F, 0x3F,               // 0x67 => g

    0xFE, 0xFE, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,               // 0x68 => h

    0x00, 0x60, 0xEC, 0xEC, 0x00, 0x00,
    0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60,                                 // 0x69 => i

    0x00, 0x00, 0x00, 0x60, 0xEC, 0xEC,
    0x60, 0xE0, 0xC0, 0xC0, 0xFF, 0x7F,                                 // 0x6A => j

    0xFE, 0xFE, 0x00, 0x80, 0xC0, 0xE0, 0x60, 0x00,
    0x7F, 0x7F, 0x07, 0x0F, 0x1D, 0x38, 0x70, 0x60,                     // 0x6B => k

    0x00, 0x06, 0xFE, 0xFE, 0x00, 0x00,
    0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60,                                 // 0x6C => l

    0xE0, 0xC0, 0xE0, 0xE0, 0xC0, 0xC0, 0xE0, 0xE0, 0xC0, 0x80,
    0x7F, 0x7F, 0x00, 0x00, 0x7F, 0x7F, 0x00, 0x00, 0x7F, 0x7F,         // 0x6D => m

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,               // 0x6E => n

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,               // 0x6F => o

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0xFF, 0xFF, 0x0C, 0x18, 0x18, 0x18, 0x1C, 0x0F, 0x07,               // 0x70 => p

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0,
    0x07, 0x0F, 0x1C, 0x18, 0x18, 0x18, 0x0C, 0xFF, 0xFF,               // 0x71 => q

    0xE0, 0xE0, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                     // 0x72 => r

    0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x40,
    0x23, 0x67, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C,                     // 0x73 => s

    0x60, 0x60, 0xFF, 0xFF, 0x60, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x3F, 0x7F, 0x60, 0x60, 0x70, 0x30,                     // 0x74 => t

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x30, 0x7F, 0x7F,               // 0x75 => u

    0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x60,
    0x00, 0x01, 0x07, 0x1E, 0x78, 0x1E, 0x07, 0x01, 0x00,               // 0x76 => v

    0xE0, 0xE0, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0xE0, 0xE0,
    0x0F, 0x3F, 0x70, 0x38, 0x1F, 0x1F, 0x38, 0x70, 0x3F, 0x0F,         // 0x77 => w

    0x60, 0xE0, 0xC0, 0x80, 0x00, 0x80, 0xC0, 0xE0, 0x60,
    0x60, 0x70, 0x39, 0x1F, 0x0F, 0x1F, 0x39, 0x70, 0x60,               // 0x78 => x

    0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x00, 0xC1, 0xC7, 0xCE, 0xEC, 0x7C, 0x1E, 0x07, 0x01,               // 0x79 => y

    0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0, 0x60,
    0x60, 0x70, 0x78, 0x6C, 0x66, 0x63, 0x61, 0x60, 0x60,               // 0x7A => z

    0x80, 0xC0, 0xFC, 0x7E, 0x07, 0x03,
    0x01, 0x03, 0x3F, 0x7E, 0xE0, 0xC0,                                 // 0x7B => {

    0xFE, 0xFE,
    0x7F, 0x7F,                                                         // 0x7C => |

    0x03, 0x07, 0x7E, 0xFC, 0xC0, 0x80,
    0xC0, 0xE0, 0x7E, 0x3F, 0x03, 0x01,                                 // 0x7D => }

    0x20, 0x30, 0x18, 0x08, 0x18, 0x30, 0x20, 0x30, 0x18, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // 0x7E => ~

    0x00, 0x00,
    0x00, 0x00,                                                         // 0x7F => 

    0x00,
    0x00,                                                               // 0x80 => Ђ

    0x00,
    0x00,                                                               // 0x81 => Ѓ

    0x00,
    0x00,                                                               // 0x82 => ‚

    0x00,
    0x00,                                                               // 0x83 => ѓ

    0x00,
    0x00,                                                               // 0x84 => „

    0x00,
    0x00,                                                               // 0x85 => …

    0x00,
    0x00,                                                               // 0x86 => †

    0x00,
    0x00,                                                               // 0x87 => ‡

    0x00,
    0x00,                                                               // 0x88 => €

    0x00,
    0x00,                                                               // 0x89 => ‰

    0x00,
    0x00,                                                               // 0x8A => Љ

    0x00,
    0x00,                                                               // 0x8B => ‹

    0x00,
    0x00,                                                               // 0x8C => Њ

    0x00,
    0x00,                                                               // 0x8D => Ќ

    0x00,
    0x00,                                                               // 0x8E => Ћ

    0x00,
    0x00,                                                               // 0x8F => Џ

    0x00,
    0x00,                                                               // 0x90 => ђ

    0x00,
    0x00,                                                               // 0x91 => ‘

    0x00,
    0x00,                                                               // 0x92 => ’

    0x00,
    0x00,                                                               // 0x93 => “

    0x00,
    0x00,                                                               // 0x94 => ”

    0x00,
    0x00,                                                               // 0x95 => •

    0x00,
    0x00,                                                               // 0x96 => –

    0x00,
    0x00,                                                               // 0x97 => —

    0x00,
    0x00,                                                               // 0x98 => �

    0x00,
    0x00,                                                               // 0x99 => ™

    0x00,
    0x00,                                                               // 0x9A => љ

    0x00,
    0x00,                                                               // 0x9B => ›

    0x00,
    0x00,                                                               // 0x9C => њ

    0x00,
    0x00,                                                               // 0x9D => ќ

    0x00,
    0x00,                                                               // 0x9E => ћ

    0x00,
    0x00,                                                               // 0x9F => џ

    0x00,
    0x00,                                                               // 0xA0 =>

    0x00,
    0x00,                                                               // 0xA1 => Ў

    0x00,
    0x00,                                                               // 0xA2 => ў

    0x00,
    0x00,                                                               // 0xA3 => Ј

    0x00,
    0x00,                                                               // 0xA4 => ¤

    0x00,
    0x00,                                                               // 0xA5 => Ґ

    0x00,
    0x00,                                                               // 0xA6 => ¦

    0x00,
    0x00,                                                               // 0xA7 => §

    0xF8, 0xF8, 0x9B, 0x9B, 0x98, 0x98, 0x9B, 0x9B, 0x98, 0x18,
    0x7F, 0x7F, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x60,         // 0xA8 => Ё

    0x00,
    0x00,                                                               // 0xA9 => ©

    0x00,
    0x00,                                                               // 0xAA => Є

    0x00,
    0x00,                                                               // 0xAB => «

    0x00,
    0x00,                                                               // 0xAC => ¬

    0x00,
    0x00,                                                               // 0xAD => ­

    0x00,
    0x00,                                                               // 0xAE => ®

    0x00,
    0x00,                                                               // 0xAF => Ї

    0x7C, 0xFE, 0xC6, 0xC6, 0xC6, 0xFE, 0x7C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                           // 0xB0 => °

    0x60, 0x60, 0x60, 0xFC, 0xFC, 0x60, 0x60, 0x60,
    0x18, 0x18, 0x18, 0x1B, 0x1B, 0x18, 0x18, 0x18,                     // 0xB1 => ±

    0x00,
    0x00,                                                               // 0xB2 => І

    0x00,
    0x00,                                                               // 0xB3 => і

    0x00,
    0x00,                                                               // 0xB4 => ґ

    0x00,
    0x00,                                                               // 0xB5 => µ

    0x00,
    0x00,                                                               // 0xB6 => ¶

    0x00,
    0x00,                                                               // 0xB7 => ·

    0x80, 0xC0, 0xEC, 0x6C, 0x60, 0x6C, 0x6C, 0xC0, 0x80,
    0x1F, 0x3F, 0x76, 0x66, 0x66, 0x66, 0x66, 0x27, 0x03,               // 0xB8 => ё

    0x00,
    0x00,                                                               // 0xB9 => №

    0x00,
    0x00,                                                               // 0xBA => є

    0x00,
    0x00,                                                               // 0xBB => »

    0x00,
    0x00,                                                               // 0xBC => ј

    0x00,
    0x00,                                                               // 0xBD => Ѕ

    0x00,
    0x00,                                                               // 0xBE => ѕ

    0x00,
    0x00,                                                               // 0xBF => ї

    0xF0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0,
    0x7F, 0x7F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x7F, 0x7F,         // 0xC0 => А

    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x86, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,         // 0xC1 => Б

    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x00,
    0x7F, 0x7F, 0x61, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0xC2 => В

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,               // 0xC3 => Г

    0x00, 0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00,
    0xE0, 0xFF, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7F, 0xFF, 0xE0,   // 0xC4 => Д

    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x06,
    0x7F, 0x7F, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x60,         // 0xC5 => Е

    0x3E, 0x78, 0xE0, 0x80, 0xFE, 0xFE, 0x80, 0xE0, 0x78, 0x3E,
    0x7C, 0x1E, 0x07, 0x01, 0x7F, 0x7F, 0x01, 0x07, 0x1E, 0x7C,         // 0xC6 => Ж

    0x18, 0x1C, 0x0E, 0x06, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78,
    0x18, 0x38, 0x70, 0x60, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E,         // 0xC7 => З

    0xFE, 0xFE, 0x00, 0x00, 0x80, 0xE0, 0x70, 0x1C, 0xFE, 0xFE,
    0x7F, 0x7F, 0x38, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x7F, 0x7F,         // 0xC8 => И

    0xFE, 0xFE, 0x00, 0x01, 0x83, 0xE3, 0x71, 0x1C, 0xFE, 0xFE,
    0x7F, 0x7F, 0x38, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x7F, 0x7F,         // 0xC9 => Й

    0xFE, 0xFE, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06,
    0x7F, 0x7F, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0x60,         // 0xCA => К

    0x00, 0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0xFE, 0xFE,
    0x60, 0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,         // 0xCB => Л

    0xFE, 0xFE, 0x3C, 0xF0, 0xC0, 0xC0, 0xF0, 0x3C, 0xFE, 0xFE,
    0x7F, 0x7F, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x7F, 0x7F,         // 0xCC => М

    0xFE, 0xFE, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE,
    0x7F, 0x7F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7F, 0x7F,         // 0xCD => Н

    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,         // 0xCE => О

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,         // 0xCF => П

    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0xF8,
    0x7F, 0x7F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00,         // 0xD0 => Р

    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0x18,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x18,         // 0xD1 => С

    0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06,
    0x00, 0x00, 0x00, 0x7F, 0x7F, 0x00, 0x00, 0x00,                     // 0xD2 => Т

    0x7E, 0xFE, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE,
    0x30, 0x70, 0x61, 0x61, 0x61, 0x61, 0x61, 0x71, 0x3F, 0x1F,         // 0xD3 => У

    0xF8, 0xFC, 0x0C, 0x0C, 0xFE, 0xFE, 0x0C, 0x0C, 0xFC, 0xF8,
    0x0F, 0x1F, 0x18, 0x18, 0x7F, 0x7F, 0x18, 0x18, 0x1F, 0x0F,         // 0xD4 => Ф

    0x06, 0x1E, 0x38, 0x60, 0xC0, 0xC0, 0x60, 0x38, 0x1E, 0x06,
    0x60, 0x78, 0x1C, 0x06, 0x03, 0x03, 0x06, 0x1C, 0x78, 0x60,         // 0xD5 => Х

    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7F, 0xFF, 0xE0,   // 0xD6 => Ц

    0x7E, 0xFE, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7F, 0x7F,         // 0xD7 => Ч

    0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE,
    0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F,         // 0xD8 => Ш

    0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x7F, 0xFF, 0xE0,   // 0xD9 => Щ

    0x06, 0x06, 0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00,
    0x00, 0x00, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,   // 0xDA => Ъ

    0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFE, 0xFE,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F, 0x00, 0x7F, 0x7F,   // 0xDB => Ы

    0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,               // 0xDC => Ь

    0x18, 0x1C, 0x0E, 0x06, 0x86, 0x86, 0x86, 0x8E, 0xFC, 0xF8,
    0x18, 0x38, 0x70, 0x60, 0x61, 0x61, 0x61, 0x71, 0x3F, 0x1F,         // 0xDD => Э

    0xFE, 0xFE, 0x80, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xF8,
    0x7F, 0x7F, 0x01, 0x1F, 0x3F, 0x70, 0x60, 0x60, 0x70, 0x3F, 0x1F,   // 0xDE => Ю

    0xF8, 0xFC, 0x8E, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE,
    0x60, 0x71, 0x3B, 0x1F, 0x0F, 0x07, 0x03, 0x03, 0x7F, 0x7F,         // 0xDF => Я

    0x00, 0x40, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0,
    0x38, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7F, 0x7F,               // 0xE0 => а

    0xF0, 0xF8, 0x9C, 0xCC, 0xCC, 0xCC, 0xCC, 0x8E, 0x06,
    0x3F, 0x7F, 0x61, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F,               // 0xE1 => б

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x00,
    0x7F, 0x7F, 0x66, 0x66, 0x66, 0x67, 0x6F, 0x7D, 0x38,               // 0xE2 => в

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                     // 0xE3 => г

    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xE0, 0x00,
    0xE0, 0xFF, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x7F, 0xFF, 0xE0,         // 0xE4 => д

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xC0, 0x80,
    0x1F, 0x3F, 0x76, 0x66, 0x66, 0x66, 0x66, 0x27, 0x03,               // 0xE5 => е

    0xE0, 0xE0, 0x80, 0x00, 0xE0, 0xE0, 0x00, 0x80, 0xE0, 0xE0,
    0x70, 0x79, 0x1F, 0x06, 0x7F, 0x7F, 0x06, 0x1F, 0x79, 0x70,         // 0xE6 => ж

    0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x00,
    0x60, 0x60, 0x66, 0x66, 0x66, 0x67, 0x6F, 0x7D, 0x38,               // 0xE7 => з

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xE0,
    0x7F, 0x7F, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x7F, 0x7F,               // 0xE8 => и

    0xE0, 0xE0, 0x08, 0x18, 0x10, 0x18, 0x88, 0xE0, 0xE0,
    0x7F, 0x7F, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x7F, 0x7F,               // 0xE9 => й

    0xE0, 0xE0, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x60, 0x00,
    0x7F, 0x7F, 0x06, 0x07, 0x0F, 0x1D, 0x38, 0x70, 0x60,               // 0xEA => к

    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xE0,
    0x60, 0x7F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,               // 0xEB => л

    0xE0, 0xE0, 0xE0, 0xC0, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xE0,
    0x7F, 0x7F, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x7F, 0x7F,         // 0xEC => м

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x7F, 0x7F, 0x06, 0x06, 0x06, 0x06, 0x7F, 0x7F,                     // 0xED => н

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x70, 0x3F, 0x1F,               // 0xEE => о

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0,
    0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F,               // 0xEF => п

    0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0xFF, 0xFF, 0x0C, 0x18, 0x18, 0x18, 0x1C, 0x0F, 0x07,               // 0xF0 => р

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xC0, 0x80,
    0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 0x60, 0x30, 0x10,               // 0xF1 => с

    0x60, 0x60, 0x60, 0xE0, 0xE0, 0x60, 0x60, 0x60,
    0x00, 0x00, 0x00, 0x7F, 0x7F, 0x00, 0x00, 0x00,                     // 0xF2 => т

    0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x00, 0xC1, 0xC7, 0xCE, 0xEC, 0x7C, 0x1E, 0x07, 0x01,               // 0xF3 => у

    0xC0, 0xE0, 0x60, 0x60, 0xF0, 0xF0, 0x60, 0x60, 0xE0, 0xC0,
    0x1F, 0x3F, 0x30, 0x30, 0xFF, 0xFF, 0x30, 0x30, 0x3F, 0x1F,         // 0xF4 => ф

    0x60, 0xE0, 0xC0, 0x80, 0x00, 0x80, 0xC0, 0xE0, 0x60,
    0x60, 0x70, 0x39, 0x1F, 0x0F, 0x1F, 0x39, 0x70, 0x60,               // 0xF5 => х

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x7F, 0xFF, 0xE0,               // 0xF6 => ц

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x03, 0x07, 0x06, 0x06, 0x06, 0x06, 0x7F, 0x7F,                     // 0xF7 => ч

    0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0,
    0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F,         // 0xF8 => ш

    0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x7F, 0xFF, 0xE0,   // 0xF9 => щ

    0x60, 0x60, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0x7F, 0x63, 0x63, 0x63, 0x77, 0x3E, 0x1C,         // 0xFA => ъ

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
    0x7F, 0x7F, 0x63, 0x63, 0x77, 0x3E, 0x1C, 0x00, 0x7F, 0x7F,         // 0xFB => ы

    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0x7F, 0x63, 0x63, 0x63, 0x77, 0x3E, 0x1C,                     // 0xFC => ь

    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80,
    0x19, 0x39, 0x70, 0x60, 0x66, 0x66, 0x76, 0x3F, 0x1F,               // 0xFD => э

    0xE0, 0xE0, 0x00, 0x80, 0xC0, 0xE0, 0x60, 0xE0, 0xC0, 0x80,
    0x7F, 0x7F, 0x06, 0x1F, 0x3F, 0x70, 0x60, 0x70, 0x3F, 0x1F,         // 0xFE => ю

    0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0,
    0x63, 0x77, 0x3E, 0x1C, 0x0C, 0x0C, 0x0C, 0x7F, 0x7F,               // 0xFF => я
};
