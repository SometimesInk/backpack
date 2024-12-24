#include "command_handler.h"
#include "input_handler.h"
#include <string.h>

// Returns: 0 --- Failed
//          1 --- Success
int parse_command() {
  char buffer[100];
  strncpy(buffer, COMMAND_INPUT, sizeof(buffer));

  char *command = strtok(buffer, " ");
  char *arguments = strtok(NULL, "");

  if (strcmp(command, "q") == 0) {
    return 0;
  }

  return 1;
}
