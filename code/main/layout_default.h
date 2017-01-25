#ifndef LAYOUT_DEFAULT_H
#define LAYOUT_DEFAULT_H

#include "main.h"

LayoutKey defaultLayout[rowsCount][columnsCount] = {
  {
    { KEY_ESC, COLOR_RED },
    { KEY_TILDE, COLOR_BLUE },
    { KEY_Q, COLOR_BLUE },
    { KEY_W, COLOR_BLUE },
    { KEY_E, COLOR_BLUE },
    { KEY_R, COLOR_BLUE },
    { KEY_T, COLOR_BLUE },
    { KEY_Y, COLOR_BLUE},
    { KEY_U, COLOR_BLUE },
    { KEY_I, COLOR_BLUE },
    { KEY_O, COLOR_BLUE },
    { KEY_P, COLOR_BLUE },
    { KEY_BACKSPACE, COLOR_RED }
  },
  {
    { KEY_MODE, COLOR_YELLOW }, // TODO
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_A, COLOR_BLUE },
    { KEY_S, COLOR_BLUE },
    { KEY_D, COLOR_BLUE },
    { KEY_F, COLOR_BLUE },
    { KEY_G, COLOR_BLUE },
    { KEY_H, COLOR_BLUE },
    { KEY_J, COLOR_BLUE },
    { KEY_K, COLOR_BLUE },
    { KEY_L, COLOR_BLUE },
    { KEY_LEFT_BRACE, COLOR_BLUE },
    { KEY_RIGHT_BRACE, COLOR_BLUE }
  },
  {
    { KEY_NUMPAD, COLOR_YELLOW }, // TODO
    { MODIFIERKEY_SHIFT, COLOR_FUCHSIA },
    { KEY_Z, COLOR_BLUE },
    { KEY_X, COLOR_BLUE },
    { KEY_C, COLOR_BLUE },
    { KEY_V, COLOR_BLUE },
    { KEY_B, COLOR_BLUE },
    { KEY_N, COLOR_BLUE },
    { KEY_M, COLOR_BLUE },
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_UP, COLOR_YELLOW },
    { KEY_ENTER, COLOR_GREEN }
  },
  {
    { KEY_F3, COLOR_YELLOW }, // TODO
    { MODIFIERKEY_CTRL, COLOR_FUCHSIA },
    { MODIFIERKEY_GUI, COLOR_FUCHSIA },
    { MODIFIERKEY_ALT, COLOR_FUCHSIA },
    { KEY_F4, COLOR_YELLOW }, // TODO
    { KEY_SPACE, COLOR_AQUA },
    { KEY_SPACE, COLOR_AQUA },
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_A, COLOR_BLUE }, // TODO
    { KEY_LEFT, COLOR_YELLOW },
    { KEY_DOWN, COLOR_YELLOW },
    { KEY_RIGHT, COLOR_YELLOW }
  }
};

#endif
