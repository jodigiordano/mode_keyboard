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

const uint16_t KEY_NOOP = -1;
const uint16_t KEY_NUMPAD = -2;
const uint16_t KEY_PLUS = -3;
const uint16_t KEY_MODE = -4;

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
