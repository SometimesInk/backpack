#include "command_handler.h"
#include "command_logic_add.h"
#include "command_logic_echo.h"
#include "command_logic_export.h"
#include "input_handler.h"
#include "items.h"
#include "modes.h"
#include "string_manipulations.h"
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
    strncpy(output, items_render_all(), sizeof(output) - 1);
    output[sizeof(output) - 1] = '\0';
  } else if (strcmp(command, "export") == 0) {
    strncpy(output, parse_command_execute_export(arguments),
            sizeof(output) - 1);
    output[sizeof(output) - 1] = '\0';
  } else if (strcmp(command, "add") == 0) {
    strncpy(output, parse_command_execute_add(arguments), sizeof(output) - 1);
    output[sizeof(output) - 1] = '\0';
  } else if (strcmp(command, "debug") == 0) {
    char *formatted_string = format_string("%i", 1231);
    strncpy(output, formatted_string, sizeof(output) - 1);
    free(formatted_string);
    output[sizeof(output) - 1] = '\0';
  } else {
    strncpy(output, "E1: Unknown command", sizeof(output) - 1);
    output[sizeof(output) - 1] = '\0';
  }

  exit_command_mode(EXIT_COMMAND_MODE_CLEAR_ALL, 1, output);
  return 1;
}
