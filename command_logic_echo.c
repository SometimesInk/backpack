#include "command_logic_echo.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *parse_environment_variable(char *variable) {
  char *environment_var = getenv(variable + 1);
  return (environment_var == NULL) ? "E5: Environment variable is NULL"
                                   : environment_var;
}

char *parse_element(char *element) {
  char first;
  char last;
  // Check if element is neither null or empty
  if (element != NULL && element[0] != '\0') {
    first = element[0];
    last = element[strlen(element) - 1];
  } else {
    return "Element is NULL or empty";
  }

  // Check if element is an environment variable
  if (first == '$') {
    return parse_environment_variable(element);
  }

  return element;
}

char *parse_command_execute_echo(char *arguments) {
  char *result = malloc(1);

  // Check if successfully allocated memory
  if (result == NULL) {
    return "E6: Failed to allocate memory";
  }

  result[0] = '\0';

  char *element = strtok(arguments, " ");
  int first_element = 1;
  while (element != NULL) {
    char *parsed = parse_element(element);

    if (!first_element) {
      // Space results between each other
      size_t current_length = strlen(result);

      // Add space and null terminator
      result = realloc(result, current_length + 2);
      strcat(result, " ");
    }

    // Concatenate the parsed element
    size_t current_length = strlen(result);
    size_t parsed_length = strlen(parsed);

    // Allocate space for parsed element
    result = realloc(result, current_length + parsed_length + 1);

    strcat(result, parsed);

    first_element = 0;
    element = strtok(NULL, " ");
  }

  return result;
}
