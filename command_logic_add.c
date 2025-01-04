#include "command_logic_add.h"
#include "items.h"
#include "string_manipulations.h"
#include <stdlib.h>
#include <string.h>

char *parse_command_execute_add(char *arguments) {
  Item item;

  char name[sizeof(item.name)];
  Item_Type type;

  // Loop for each word in arguments
  char *element = strtok(arguments, " ");
  char *formatted_element;
  int i = 0;
  while (element != NULL) {
    if (i == 0) {
      // Find type as an integer
      type = strtol(element, NULL, 10);
      item.type = type;
    } else {
      // Add element to name
      formatted_element = format_string("%s ", element);
      strcat(name, formatted_element);
      free(formatted_element);
    }

    // Go to next argument
    element = strtok(NULL, " ");
    i++;
  }

  items_add_item(item);

  return "Added item.";
}
