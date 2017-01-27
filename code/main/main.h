#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

// Digital pins used on the Teensy for rows of the keyboard matrix.
const uint8_t rowsCount = 4;
const uint8_t rows[rowsCount] = {
  14, 15, 16, 17
};

// Digital pins used on the Teensy for columns of the keyboard matrix.
const uint8_t columnsCount = 13;
const uint8_t columns[columnsCount] = {
  18, 19, 20, 21, 1, 2, 23, 22, 8, 9, 10, 11, 12
};

struct Key {
  uint8_t row;
  uint8_t column;
  uint8_t rPin;
  uint8_t gPin;
  uint8_t bPin;
  boolean pressed;
};

// A lot of keys are already defined here:
// https://github.com/PaulStoffregen/cores/blob/master/teensy/keylayouts.h
// Here I define additional keys in an unused namespace:

const uint16_t KEY_LAYOUT_MODE               = 1 | 0xA000;
const uint16_t KEY_LAYOUT_NUMPAD             = 2 | 0xA000;
const uint16_t KEY_LAYOUT_FR                 = 3 | 0xA000;
const uint16_t KEY_LAYOUT_SYMBOLS            = 4 | 0xA000;
const uint16_t KEY_LAYOUT_FUNCTIONS          = 5 | 0xA000;
const uint16_t KEY_LAYOUT_WINDOW_MANAGER     = 6 | 0xA000;
const uint16_t KEY_LAYOUT_KEYBOARD           = 7 | 0xA000;
const uint16_t KEY_LAYOUT_MEDIA              = 8 | 0xA000;
const uint16_t KEY_LAYOUT_SYSTEM             = 9 | 0xA000;

const uint16_t KEY_NOOP                      = 10 | 0xA000;

const uint16_t KEY_FR_E                      = 11 | 0xA000; // é
const uint16_t KEY_FR_EE                     = 12 | 0xA000; // è
const uint16_t KEY_FR_A                      = 13 | 0xA000; // à
const uint16_t KEY_FR_C                      = 14 | 0xA000; // ç
const uint16_t KEY_FR_U                      = 15 | 0xA000; // ù
const uint16_t KEY_FR_UU                     = 16 | 0xA000; // û
const uint16_t KEY_FR_I                      = 17 | 0xA000; // ï

const uint16_t KEY_SYMBOL_EXCLAMATION_MARK   = 17 | 0xA000; // !
const uint16_t KEY_SYMBOL_COMMERCIAL_A       = 18 | 0xA000; // @
const uint16_t KEY_SYMBOL_SHARP              = 19 | 0xA000; // #
const uint16_t KEY_SYMBOL_DOLLAR             = 20 | 0xA000; // $
const uint16_t KEY_SYMBOL_PERCENT            = 21 | 0xA000; // %
const uint16_t KEY_SYMBOL_CIRCUMFLEX         = 22 | 0xA000; // ^
const uint16_t KEY_SYMBOL_AMPERSAND          = 23 | 0xA000; // &
const uint16_t KEY_SYMBOL_ASTERIX            = 24 | 0xA000; // *
const uint16_t KEY_SYMBOL_LEFT_PARENTHESIS   = 25 | 0xA000; // (
const uint16_t KEY_SYMBOL_RIGHT_PARENTHESIS  = 26 | 0xA000; // )
const uint16_t KEY_SYMBOL_UNDERSCORE         = 27 | 0xA000; // _
const uint16_t KEY_SYMBOL_PIPE               = 28 | 0xA000; // |
const uint16_t KEY_SYMBOL_LEFT_CHEVRON       = 29 | 0xA000; // <
const uint16_t KEY_SYMBOL_RIGHT_CHEVRON      = 30 | 0xA000; // >
const uint16_t KEY_SYMBOL_QUESTION_MARK      = 31 | 0xA000; // ?
const uint16_t KEY_SYMBOL_COLON              = 32 | 0xA000; // :
const uint16_t KEY_SYMBOL_DOUBLE_QUOTE       = 33 | 0xA000; // "
const uint16_t KEY_SYMBOL_LEFT_BRACE         = 34 | 0xA000; // {
const uint16_t KEY_SYMBOL_RIGHT_BRACE        = 35 | 0xA000; // }
const uint16_t KEY_SYMBOL_TILDE              = 36 | 0xA000; // }

const uint16_t KEY_BACKTICK                  = KEY_TILDE;
const uint16_t KEY_LEFT_BRACKET              = KEY_LEFT_BRACE;
const uint16_t KEY_RIGHT_BRACKET             = KEY_RIGHT_BRACE;

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

const Color COLOR_WHITE = { 255, 255, 255 };
const Color COLOR_PURPLE = { 200, 0, 128 };
const Color COLOR_RED = { 255, 0, 0 };
const Color COLOR_GREEN = { 0, 255, 0 };
const Color COLOR_BLUE = { 0, 0, 255 };
const Color COLOR_AQUA = { 0, 255, 255 };
const Color COLOR_YELLOW = { 255, 255, 0 };
const Color COLOR_FUCHSIA = { 255, 0, 255 };
const Color COLOR_BLACK = { 0, 0, 0 };

struct LayoutKey {
  uint16_t code;
  Color color;
};

#endif
