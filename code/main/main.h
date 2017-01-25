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

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  float a;
};

struct LayoutKey {
  uint16_t code;
  Color color;
};

#endif
