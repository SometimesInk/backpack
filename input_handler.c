#include "input_handler.h"
#include "command_handler.h"
#include "modes.h"
#include <ncurses.h>

char NORMAL_INPUT[100] = "";
char COMMAND_INPUT[100] = "";
int normal_used_length = 1;
int command_used_length = 1;

// Sets the value of "holder" variable to the keycode of the pressed key
// Returns: 1 --- Success
int get_input(int *holder) {
  *holder = getch();
  return 1;
}

// Adds key presses to NORMAL/COMMAND_INPUT
// Returns: -1 --- Error (code 1)
//           1 --- Success
int parse_key(int input) {
  if (CURRENT_MODE == COMMAND) {
    if (input == 10) { // Enter key
      // Parse command
      return parse_command();
    } else {
      // Find the length of the array
      int command_input_length = sizeof(COMMAND_INPUT) - 1;

      // Handle backspace
      if (input == 263) {
        // Remove key
        remove_character(COMMAND_INPUT, 100, command_used_length);
        command_used_length = command_used_length - 1;

        // Cap the cursor
        if (command_used_length < 1) {
          command_used_length = 1;
        }
      } else {
        // Add key
        modify_character(COMMAND_INPUT, 100, command_used_length, input);
        command_used_length = command_used_length + 1;
      }
    }
  } else {
    switch (input) {
    case 'q':
      return 0;
    case 58: // Colon
      if (CURRENT_MODE != COMMAND)
        CURRENT_MODE = COMMAND;
      break;
    }
  }

  mvprintw(0, 0, "N%i;K%c;M%s", input, input, mode_as_string(CURRENT_MODE));

  mvprintw(25, 0, "%s", COMMAND_INPUT);
  return 1;
}

// Modifies the Nth character of a string to another
// Returns: -N --- Error (code N)
//           1 --- Success
int modify_character(char *string, int size, int position, char character) {
  // Make sure the position is within bounds
  if (position >= 1 && position <= size) {
    string[position - 1] = character;
    return 1;
  } else {
    return -1;
  }
}

// Removes the Nth character of a string
// Returns: -N --- Error (code N)
//           1 --- Success
int remove_character(char *string, int size, int position) {
  // Make sure the position is within bounds
  if (position >= 1 && position <= size) {
    // Shift the characters to the left starting from said position
    for (int i = position - 1; i < size - 1; i++) {
      string[i] = string[i + 1];
    }
    string[size - 1] = '\0';
    return 1;
  } else {
    return -1;
  }
}
