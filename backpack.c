#include "input_handler.h"
#include "items.h"
#include "main_handler.h"
#include "terminal.h"
#include "window_handler.h"
#include <ncurses.h>
#include <stdlib.h>

int main() {
  // Initialize key registering variable
  int ch;

  // Initialize ncurses
  initscr();

  // Full terminal control
  raw();
  keypad(stdscr, TRUE);
  noecho();

  // Check for colors, this may cause troubles on Kitty terminal
  if (!has_colors()) {
    printw("E3: Terminal has no colors");
    getch();
    endwin();
    return EXIT_SUCCESS;
  }

  // Initialize colors
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_RED);
  init_pair(4, COLOR_GREEN, COLOR_RED);
  init_pair(5, COLOR_WHITE, COLOR_RED);
  init_pair(6, COLOR_YELLOW, COLOR_RED);
  init_pair(7, COLOR_CYAN, COLOR_RED);

  // Initialize terminal and windows
  terminal_initialize();
  windows_initialize();
  if (items_initialize() == -6) {
    printw("E6: Failed to allocate memory");
    getch();
    endwin();
    return EXIT_SUCCESS;
  }

  while (get_input(&ch) && handle(ch))
    ;

  endwin();
  free(ITEMS);
  return EXIT_SUCCESS;
}
