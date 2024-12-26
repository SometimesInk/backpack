#include "command_logic_add.h"
#include "items.h"
#include <string.h>

char *parse_command_execute_add(char *arguments) {
  Item item;

  char name[sizeof(item.name)];
  Item_Type type;

  // Parse item
  char *element = strtok(arguments, " ");
  int i = 0;
  while (element != NULL) {
    switch (i) {
    case 0:
      // Copy element to name
      strncpy(item.name, element, sizeof(name));
      name[sizeof(name) - 1] = '\0';
      break;
    case 1:
      if (strcmp(element, "0") == 0) {
        item.type = 0;
      } else if (strcmp(element, "1") == 0) {
        item.type = 1;
      } else if (strcmp(element, "2") == 0) {
        item.type = 2;
      } else if (strcmp(element, "3") == 0) {
        item.type = 3;
      } else {
        return "E9: Invalid argument";
      }
      break;
    }

    element = strtok(NULL, " ");
    i++;
  }

  items_add_item(item);

  return "Successfully added item";
}
