#ifndef LAYOUT_FN_H
#define LAYOUT_FN_H

#include "main.h"

LayoutKey fnLayout[rowsCount][columnsCount] = {
  {
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_F7, COLOR_WHITE },
    { KEY_F8, COLOR_WHITE },
    { KEY_F9, COLOR_WHITE },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK }
  },
  {
    { KEY_LAYOUT_MODE, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_F4, COLOR_WHITE },
    { KEY_F5, COLOR_WHITE },
    { KEY_F6, COLOR_WHITE },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK }
  },
  {
    { KEY_NOOP, COLOR_BLACK },
    { MODIFIERKEY_SHIFT, COLOR_FUCHSIA },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_F1, COLOR_WHITE },
    { KEY_F2, COLOR_WHITE },
    { KEY_F3, COLOR_WHITE },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK }
  },
  {
    { KEY_LAYOUT_FUNCTIONS, COLOR_BLACK },
    { MODIFIERKEY_CTRL, COLOR_FUCHSIA },
    { MODIFIERKEY_GUI, COLOR_FUCHSIA },
    { MODIFIERKEY_ALT, COLOR_FUCHSIA },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_NOOP, COLOR_BLACK },
    { KEY_F10, COLOR_WHITE },
    { KEY_F11, COLOR_WHITE },
    { KEY_F12, COLOR_WHITE }
  }
};

#endif
