#include "modes.h"

Mode CURRENT_MODE = NORMAL;

const char *mode_as_string(Mode mode) {
  switch (mode) {
  case NORMAL:
    return "NORMAL";
  case COMMAND:
    return "COMMAND";
  default:
    return "E0: Unknown mode.";
  }
}
