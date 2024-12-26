#include "input_handler.h"
#include "command_handler.h"
#include "modes.h"
#include "string_manipulations.h"
#include "terminal.h"
#include "window_handler.h"
#include <ncurses.h>
#include <string.h>

char COMMAND_INPUT[100] = "";
int COMMAND_USED_INPUT = 1;

int get_input(int *holder) {
  *holder = getch();
  return 1;
}

int parse_key(int input) {
  if (MODE_CURRENT == MODE_COMMAND) {
    // Parse key as a command
    if (parse_key_command(input) == 2)
      return parse_command();

    // Update command_window
    mvwprintw(WINDOW_COMMAND, 0, COLUMNS - 5, "%i", input);
    mvwprintw(WINDOW_COMMAND, 0, 1, "%s", COMMAND_INPUT);
  } else {
    switch (input) {
    case 58: // Colon
      if (MODE_CURRENT != MODE_COMMAND) {
        // Clear command system and add command symbol
        exit_command_mode(EXIT_COMMAND_MODE_CLEAR_ALL_ADDITIVE, 0, NULL);
        MODE_CURRENT = MODE_COMMAND;
      }
      break;
    }
  }
  wrefresh(WINDOW_COMMAND);
  return 1;
}

int parse_key_command(int input) {
  // Check for enter key
  if (input == 10)
    return 2;

  // Find the length of the array
  int command_input_length = sizeof(COMMAND_INPUT) - 1;

  // Add key
  if (input != 263) {
    modify_character(COMMAND_INPUT, command_input_length, COMMAND_USED_INPUT,
                     input);
    COMMAND_USED_INPUT = COMMAND_USED_INPUT + 1;
    return 1;
  }

  // Decrease counter
  COMMAND_USED_INPUT = COMMAND_USED_INPUT - 1;

  // If trying to remove the :, exit command mode
  if (COMMAND_USED_INPUT < 1) {
    exit_command_mode(EXIT_COMMAND_MODE_CLEAR_SYMBOL, 0, NULL);
    return 1;
  }

  // Remove character from string
  remove_character(COMMAND_INPUT, command_input_length, COMMAND_USED_INPUT);

  // Remove character from command window
  mvwprintw(WINDOW_COMMAND, 0, COMMAND_USED_INPUT, " ");
  wrefresh(WINDOW_COMMAND);
  return 1;
}
