#include "main.h"
#include "leds.h"
#include "layout_default.h"
#include "layout_fn.h"
#include "layout_fr.h"
#include "layout_keyboard.h"
#include "layout_media.h"
#include "layout_mode.h"
#include "layout_numpad.h"
#include "layout_symbols.h"
#include "layout_system.h"
#include "layout_wm.h"

bool debug = false;
bool debugLedOn = false;

bool modifierCtrlPressed = false;
bool modifierShiftPressed = false;
bool modifierAltPressed = false;
bool modifierGuiPressed = false;
bool modifierModePressed = false;

LayoutKey (*currentLayout)[columnsCount] = defaultLayout;

Leds lights;

// Holds the physical -> logical mapping for keys.
//
// I made 4 connectors to connect the rows/columns to the Teensy and those
// connectors can be inversed. Also, I made this program after I connected
// everything and sealed the keyboard. Because of this and Murphy's law, I
// inversed some connectors.
//
// For example, I inversed the rows connector so the physical row/column [0, 0]
// is physically located at the bottom-left corner of my keyboard. It's like I'm
// scanning the matrix from bottom-left to top-right... well mostly, because as
// you can see below, I also inversed a column connector!
//
// For my sanity and layouts, I wanted the row/column [0,0] to represent the
// top-left corner of my keyboard (where the ESC is usually located) and [3,12]
// to represent the bottom-right corner of my keyboard. That way I can describe
// keyboard layouts like this:
//
//   ESC   KEY_Q KEY_W ...
//   SHIFT KEY_A KEY_S ...
//   ...
//
Key keys[rowsCount][columnsCount] = {
 {
   { 3, 0, 3, 4, 5, false },
   { 3, 1, 12, 13, 14, false },
   { 3, 2, 21, 37, 53, false },
   { 3, 3, 28, 44, 60, false },
   { 3, 7, 76, 92, 108, false },
   { 3, 6, 72, 88, 104, false },
   { 3, 5, 31, 47, 63, false },
   { 3, 4, 30, 46, 62, false },
   { 3, 8, 78, 94, 110, false },
   { 3, 9, 121, 137, 153, false },
   { 3, 10, 124, 140, 156, false },
   { 3, 11, 127, 143, 159, false },
   { 3, 12, 125, 141, 157, false }
 },
 {
   { 2, 0, 9, 10, 11, false },
   { 2, 1, 20, 36, 52, false },
   { 2, 2, 23, 39, 55, false },
   { 2, 3, 29, 45, 61, false },
   { 2, 7, 77, 93, 109, false },
   { 2, 6, 74, 90, 106, false },
   { 2, 5, 65, 81, 97, false },
   { 2, 4, 27, 43, 59, false },
   { 2, 8, 79, 95, 111, false },
   { 2, 9, 120, 136, 152, false },
   { 2, 10, 122, 138, 154, false },
   { 2, 11, 123, 139, 155, false },
   { 2, 12, 126, 142, 158, false }
 },
 {
   { 1, 0, 0, 1, 2, false },
   { 1, 1, 18, 34, 50, false },
   { 1, 2, 19, 35, 51, false },
   { 1, 3, 22, 38, 54, false },
   { 1, 7, 69, 85, 101, false },
   { 1, 6, 67, 83, 99, false },
   { 1, 5, 64, 80, 96, false },
   { 1, 4, 24, 40, 56, false },
   { 1, 8, 71, 87, 103, false },
   { 1, 9, 113, 129, 145, false },
   { 1, 10, 115, 131, 147, false },
   { 1, 11, 117, 133, 149, false },
   { 1, 12, 119, 135, 151, false }
 },
 {
   { 0, 0, 6, 7, 8, false },
   { 0, 1, 16, 32, 48, false },
   { 0, 2, 17, 33, 49, false },
   { 0, 3, 25, 41, 57, false },
   { 0, 7, 68, 84, 100, false },
   { 0, 6, 66, 82, 98, false },
   { 0, 5, 73, 89, 105, false },
   { 0, 4, 26, 42, 58, false },
   { 0, 8, 70, 86, 102, false },
   { 0, 9, 112, 128, 144, false },
   { 0, 10, 114, 130, 146, false },
   { 0, 11, 116, 132, 148, false },
   { 0, 12, 118, 134, 150, false }
 }
};

Key* getKey(uint8_t row, uint8_t column) {
  return &keys[row][column];
}

LayoutKey* getLayoutKey(uint8_t row, uint8_t column) {
  // TODO: use layouts depending on mode.
  return &currentLayout[row][column];
}

void setup() {
  // Setup debug.
  if (debug) {
    debugLedOn = false;
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);
  }

  // Setup keys.
  for (uint8_t i = 0; i < columnsCount; i++) {
    pinMode(columns[i], INPUT_PULLUP);
  }

  for (uint8_t i = 0; i < rowsCount; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }

  // Setup lights.
  lights.init();

  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);

  updateLayoutLights();
}

void loop() {
  logTick();

  for (uint8_t i = 0; i < rowsCount; i++) {
    digitalWrite(rows[i], LOW);

    for (uint8_t j = 0; j < columnsCount; j++) {
      Key* key = getKey(i, j);

      boolean current = !digitalRead(columns[j]);
      boolean previous = key->pressed;
      key->pressed = current;

      LayoutKey* layout = getLayoutKey(key->row, key->column);

      if (current && !previous) {
        keyPressed(key, layout);
      } else if (!current && previous) {
        keyReleased(key, layout);
      }
    }

    digitalWrite(rows[i], HIGH);
  }

  lights.update();
}

void keyPressed(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NOOP) {
    // NOOP.
  } else if (layout->code == KEY_LAYOUT_MODE) {
    modifierModePressed = true;

    if (
      currentLayout != frLayout &&
      currentLayout != fnLayout &&
      currentLayout != kbLayout &&
      currentLayout != systemLayout
    ) {
      currentLayout = modeLayout;
      updateLayoutLights();
    }
  } else if (layout->code == KEY_LAYOUT_NUMPAD) {
    currentLayout = numpadLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_FR) {
    currentLayout = frLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_SYMBOLS) {
    currentLayout = symbolsLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_FUNCTIONS) {
    currentLayout = fnLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_WINDOW_MANAGER) {
    currentLayout = wmLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_KEYBOARD) {
    currentLayout = kbLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_MEDIA) {
    currentLayout = mediaLayout;
    updateLayoutLights();
  } else if (layout->code == KEY_LAYOUT_SYSTEM) {
    currentLayout = systemLayout;
    updateLayoutLights();
  } else if (isModifier(layout)) {
    Keyboard.set_modifier(getModifierState(layout, true));

    if (!debug) {
      Keyboard.send_now();
    }
  } else {
    Keyboard.set_key1(layout->code);

    if (!debug) {
      Keyboard.send_now();
    }
  }

  if (debug) {
    logKey("pressed", key, layout);
  }
}

void keyReleased(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NOOP) {
    // NOOP.
  } else if (layout->code == KEY_LAYOUT_MODE) {
    modifierModePressed = false;

    if (currentLayout == modeLayout) {
      currentLayout = defaultLayout;
      updateLayoutLights();
    }
  } else if (
    layout->code == KEY_LAYOUT_FR ||
    layout->code == KEY_LAYOUT_FUNCTIONS ||
    layout->code == KEY_LAYOUT_KEYBOARD ||
    layout->code == KEY_LAYOUT_SYSTEM
  ) {
    if (modifierModePressed) {
      currentLayout = modeLayout;
    } else {
      currentLayout = defaultLayout;
    }

    updateLayoutLights();
  } else if (
    layout->code == KEY_LAYOUT_NUMPAD ||
    layout->code == KEY_LAYOUT_FR ||
    layout->code == KEY_LAYOUT_SYMBOLS ||
    layout->code == KEY_LAYOUT_FUNCTIONS ||
    layout->code == KEY_LAYOUT_WINDOW_MANAGER ||
    layout->code == KEY_LAYOUT_KEYBOARD ||
    layout->code == KEY_LAYOUT_MEDIA ||
    layout->code == KEY_LAYOUT_SYSTEM
  ) {
    currentLayout = defaultLayout;
    updateLayoutLights();
  } else if (isModifier(layout)) {
    Keyboard.set_modifier(getModifierState(layout, false));

    if (!debug) {
      Keyboard.send_now();
    }
  } else {
    Keyboard.set_key1(0);

    if (!debug) {
      Keyboard.send_now();
    }
  }

  if (debug) {
    logKey("released", key, layout);
  }
}

// Lights.

void updateLayoutLights() {
  for (uint8_t j = 0; j < columnsCount; j++) {
    uint8_t column = j;

    if (j == 4) {
      column = 7;
    } else if (j == 5) {
      column = 6;
    } else if (j == 6) {
      column = 5;
    } else if (j == 7) {
      column = 4;
    }

    for (uint8_t i = 0; i < rowsCount; i++) {
      Key* key = getKey(i, column);
      LayoutKey* layout = getLayoutKey(key->row, key->column);
      lights.on(key, layout);
    }

    lights.update();
    delay(5);
  }
}

// Modifiers.

bool isModifier(LayoutKey* layout) {
  return
    layout->code == MODIFIERKEY_CTRL ||
    layout->code == MODIFIERKEY_SHIFT ||
    layout->code == MODIFIERKEY_ALT ||
    layout->code == MODIFIERKEY_GUI;
}

uint8_t getModifierState(LayoutKey* layout, bool pressed) {
  if (layout->code == MODIFIERKEY_CTRL) {
    modifierCtrlPressed = pressed;
  } else if (layout->code == MODIFIERKEY_SHIFT) {
    modifierShiftPressed = pressed;
  } else if (layout->code == MODIFIERKEY_ALT) {
    modifierAltPressed = pressed;
  } else if (layout->code == MODIFIERKEY_GUI) {
    modifierGuiPressed = pressed;
  }

  uint8_t state = 0;
  state |= modifierCtrlPressed ? MODIFIERKEY_CTRL : 0;
  state |= modifierShiftPressed ? MODIFIERKEY_SHIFT : 0;
  state |= modifierAltPressed ? MODIFIERKEY_ALT : 0;
  state |= modifierGuiPressed ? MODIFIERKEY_GUI : 0;

  return state;
}

// Debug.

void logTick() {
  if (debug) {
    digitalWrite(LED_BUILTIN, debugLedOn ? HIGH : LOW);
    debugLedOn = !debugLedOn;
  }
}

void logKey(String state, Key* key, LayoutKey* layout) {
  String message = "[char ";

  message += layout->code;
  message += "]";
  message += "[pin ";
  message += key->row;
  message += ", ";
  message += key->column;
  message += "] ";
  message += state;

  Serial.println(message);
}
