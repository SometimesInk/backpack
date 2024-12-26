#include "modes.h"
#include "input_handler.h"
#include "terminal.h"
#include "window_handler.h"
#include <ncurses.h>
#include <string.h>

Mode MODE_CURRENT = MODE_NORMAL;

const char *mode_as_string(Mode mode) {
  switch (mode) {
  case MODE_NORMAL:
    return "NORMAL";
  case MODE_COMMAND:
    return "COMMAND";
  default:
    return "E0: Unknown mode";
  }
}

int exit_command_mode(Exit_Command_Mode_Clear clear, int write, char *message) {
  MODE_CURRENT = MODE_NORMAL;
  COMMAND_USED_INPUT = 1;

  // Clear COMMAND_INPUT
  if (clear == 0 || clear == 1 || clear == 4) {
    memset(COMMAND_INPUT, 0, sizeof(COMMAND_INPUT));
  }

  // Clear COMMAND_WINDOW
  if (clear == 0 || clear == 2 || clear == 4) {
    for (int i = 0; i < COLUMNS; i++) {
      mvwprintw(WINDOW_COMMAND, 0, i, " ");
    }
  }

  // Remove command symbol for clear values 0, 1, 2 and 3
  if (clear >= 0 && clear <= 3) {
    mvwprintw(WINDOW_COMMAND, 0, 0, " ");
  }

  // Add command symbol
  if (clear == 4) {
    mvwprintw(WINDOW_COMMAND, 0, 0, ":");
  }

  // Write message
  if (write == 1) {
    if (message == NULL) {
      mvwprintw(WINDOW_COMMAND, 0, 0, "E2: Message is NULL");
    } else {
      mvwprintw(WINDOW_COMMAND, 0, 0, "%s", message);
    }
  }

  wrefresh(WINDOW_COMMAND);
  return 0;
}
