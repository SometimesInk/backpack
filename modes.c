#include "modes.h"
#include "input_handler.h"
#include "terminal.h"
#include "window_handler.h"
#include <ncurses.h>
#include <string.h>

Mode CURRENT_MODE = NORMAL_MODE;

const char *mode_as_string(Mode mode) {
  switch (mode) {
  case NORMAL_MODE:
    return "NORMAL";
  case COMMAND_MODE:
    return "COMMAND";
  default:
    return "E0: Unknown mode";
  }
}

int exit_command_mode(Exit_Command_Mode_Clear clear, int write, char *message) {
  CURRENT_MODE = NORMAL_MODE;
  COMMAND_USED_INPUT = 1;

  // Clear COMMAND_INPUT
  if (clear == 0 || clear == 1 || clear == 4) {
    memset(COMMAND_INPUT, 0, sizeof(COMMAND_INPUT));
  }

  // Clear COMMAND_WINDOW
  if (clear == 0 || clear == 2 || clear == 4) {
    for (int i = 0; i < COLUMNS; i++) {
      mvwprintw(COMMAND_WINDOW, 0, i, " ");
    }
  }

  // Remove command symbol for clear values 0, 1, 2 and 3
  if (clear >= 0 && clear <= 3) {
    mvwprintw(COMMAND_WINDOW, 0, 0, " ");
  }

  // Add command symbol
  if (clear == 4) {
    mvwprintw(COMMAND_WINDOW, 0, 0, ":");
  }

  // Write message
  if (write == 1) {
    if (message == NULL) {
      mvwprintw(COMMAND_WINDOW, 0, 0, "E2: Message is NULL");
    } else {
      mvwprintw(COMMAND_WINDOW, 0, 0, "%s", message);
    }
  }

  wrefresh(COMMAND_WINDOW);
  return 0;
}
