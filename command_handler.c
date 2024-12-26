#include "command_handler.h"
#include "command_logic_echo.h"
#include "input_handler.h"
#include "items.h"
#include "modes.h"
#include <stdlib.h>
#include <string.h>

int parse_command() {
  char buffer[100];
  strncpy(buffer, COMMAND_INPUT, sizeof(buffer));

  char *command = strtok(buffer, " ");
  char *arguments = strtok(NULL, "");

  char output[100];

  if (strcmp(command, "q") == 0) {
    return 0;
  } else if (strcmp(command, "echo") == 0) {
    // Get echo output
    char *allocatedBuffer = parse_command_execute_echo(arguments);

    // Safely copy to output
    strncpy(output, allocatedBuffer, sizeof(output) - 1);

    // Free echo output memory
    free(allocatedBuffer);

    // Ensure null termination
    output[sizeof(output) - 1] = '\0';
  } else if (strcmp(command, "render") == 0) {
    // Safely copy to output
    strncpy(output, items_render_all(), sizeof(output) - 1);

    // Ensure null termination
    output[sizeof(output) - 1] = '\0';
  } else {
    // Safely copy to output
    strncpy(output, "E1: Unknown command", sizeof(output) - 1);

    // Ensure null termination
    output[sizeof(output) - 1] = '\0';
  }

  exit_command_mode(EXIT_COMMAND_MODE_CLEAR_ALL, 1, output);
  return 1;
}
