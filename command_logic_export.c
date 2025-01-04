#include "command_logic_export.h"
#include <stdlib.h>

char *parse_command_execute_export(char *argument) {
  putenv(argument);
  return "Exported.";
}
