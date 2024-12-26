#ifndef ITEMS_H
#define ITEMS_H

#include <ncurses.h>

/// Item type values:
///   0 --- Container
///   1 --- Normal
///   2 --- Magic
///   3 --- Artefact
typedef enum {
  /// 0 --- ...
  ITEM_TYPE_CONTAINER,
  /// 1 --- ...
  ITEM_TYPE_NORMAL,
  /// 2 --- ...
  ITEM_TYPE_MAGIC,
  /// 3 --- ...
  ITEM_TYPE_ARTEFACT
} Item_Type;

typedef struct {
  char name[16];
  Item_Type type;
} Item;

extern Item *ITEMS;
extern int ITEMS_NUMBER_OF_ITEMS;

/// Returns:
///  -6 --- Failed to allocate memory
///   1 --- Success
extern int items_initialize();

/// Returns the COLOR_PAIR(i) index of the color type
extern int items_get_type_color(Item_Type item_type);

/// Returns:
///  -6 --- Failed to allocate memory
///   1 --- Success
extern int items_add_item(Item item);

/// Returns:
///  -8 --- Cannot delete root
///  -7 --- Index out of bounds
///  -6 --- Memory allocation failed
///   1 --- Success
extern int items_remove_at_index(int i);

extern char *items_render_all();

#endif
