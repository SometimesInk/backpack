#include "items.h"
#include "string_manipulations.h"
#include "window_handler.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

Item *ITEMS;
int ITEMS_NUMBER_OF_ITEMS = 1;

int items_initialize() {
  // Allocate memory for items
  ITEMS = malloc(sizeof(Item));

  // Check if memory allocation succeeded
  if (ITEMS == NULL) {
    return -6;
  }

  // Assign root item
  strncpy(ITEMS[0].name, "Root", sizeof(ITEMS[0].name) - 1);
  ITEMS[0].name[sizeof(ITEMS[0].name) - 1] = '\0';

  ITEMS[0].type = ITEM_TYPE_CONTAINER;
  return 1;
}

int items_get_type_color(Item_Type item_type) { return item_type + 4; }

int items_add_item(Item item) {
  // Reallocate memory for new item
  Item *new_items = realloc(ITEMS, (ITEMS_NUMBER_OF_ITEMS + 1) * sizeof(Item));

  // Check if memory allocation succeeded
  if (new_items == NULL) {
    return -6;
  }

  // Update pointer
  ITEMS = new_items;

  // Set new item
  ITEMS[ITEMS_NUMBER_OF_ITEMS] = item;
  ITEMS_NUMBER_OF_ITEMS++;

  return 1;
}

int items_remove_at_index(int i) {
  // Check if the index is valid
  if (i < 0 || i >= ITEMS_NUMBER_OF_ITEMS) {
    return -7; // Invalid index
  }

  // Shift elements
  for (int j = i; j < ITEMS_NUMBER_OF_ITEMS - 1; j++) {
    ITEMS[j] = ITEMS[j + 1];
  }

  // Reallocate memory for smaller array
  Item *new_items = realloc(ITEMS, (ITEMS_NUMBER_OF_ITEMS - 1) * sizeof(Item));

  // Check if memory reallocation succeeded
  if (new_items == NULL && ITEMS_NUMBER_OF_ITEMS - 1 > 0) {
    return -6; // Memory allocation failed
  }

  // Update pointer and counter
  ITEMS = new_items;
  ITEMS_NUMBER_OF_ITEMS--;

  return 1;
}

char *items_render_all() {
  for (int i = 1; i < ITEMS_NUMBER_OF_ITEMS; i++) {
    int color = (items_get_type_color(ITEMS[i].type));
    wattron(WINDOW_MAIN, COLOR_PAIR(color));
    mvwprintw(WINDOW_MAIN, i, 0, "%s, %i", ITEMS[i].name, color);
    wattroff(WINDOW_MAIN, COLOR_PAIR(color));
  }

  wrefresh(WINDOW_MAIN);

  return format_string("%i", ITEMS[ITEMS_NUMBER_OF_ITEMS - 1].type);
}
