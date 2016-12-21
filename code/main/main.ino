#include "leds.h"

const uint8_t rowsCount = 4;
const uint8_t rows[rowsCount] = { 14, 15, 16, 17 };

const uint8_t columnsCount = 13;
const uint8_t columns[columnsCount] = { 1, 2, 8, 9, 10, 11, 12, 18, 19, 20, 21, 22, 23 };

boolean pressedKeys[rowsCount][columnsCount] = {
  { false, false, false, false, false, false, false, false, false, false, false, false, false },
  { false, false, false, false, false, false, false, false, false, false, false, false, false },
  { false, false, false, false, false, false, false, false, false, false, false, false, false },
  { false, false, false, false, false, false, false, false, false, false, false, false, false }
};

int defaultLayout[rowsCount][columnsCount] = {
  { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M },
  { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M },
  { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M },
  { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M }
};

const int led = LED_BUILTIN;
boolean ledOn = false;
int loopCount = 0;

boolean isModifier(uint8_t key) {
   // TODO: all possibilities.
  return key == MODIFIERKEY_SHIFT;
}

uint8_t getKey(uint8_t row, uint8_t column) {
  // TODO: use layouts.
  return defaultLayout[row][column];
}

void setup()
{
  Serial.begin(9600);

  pinMode(led, OUTPUT);

  for (int i = 0; i < columnsCount; i++) {
    pinMode(columns[i], INPUT_PULLUP);
  }

  for (int i = 0; i < rowsCount; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }
}

void loop()
{
  digitalWrite(led, ledOn ? HIGH : LOW);
  ledOn = !ledOn;

  for (int i = 0; i < rowsCount; i++) {
    digitalWrite(rows[i], LOW);

    for (int j = 0; j < columnsCount; j++) {
      boolean current = !digitalRead(columns[j]);
      boolean previous = pressedKeys[i][j];
      pressedKeys[i][j] = current;

      if (current && !previous) {
        keyPressed(i, j);
      } else if (!current && previous) {
        keyReleased(i, j);
      }
    }

    digitalWrite(rows[i], HIGH);
  }

  delay(100);
}

void keyPressed(uint8_t row, uint8_t column) {
  logKey("pressed", row, column);

  uint8_t key = getKey(row, column);

  if (isModifier(key)) {
    Keyboard.set_modifier(key);
  } else {
    Keyboard.set_key1(key);
  }

  Keyboard.send_now();
}

void keyReleased(uint8_t row, uint8_t column) {
  logKey("released", row, column);

  uint8_t key = getKey(row, column);

  if (isModifier(key)) {
    Keyboard.set_modifier(0);
  } else {
    Keyboard.set_key1(0);
  }

  Keyboard.send_now();
}

void logKey(String state, uint8_t row, uint8_t column) {
  String message = "[logic ";
  message += row;
  message += ", ";
  message += column;
  message += "]";
  message += "[pin ";
  message += rows[row];
  message += ", ";
  message += columns[column];
  message += "] ";
  message += state;

  Serial.println(message);
}
