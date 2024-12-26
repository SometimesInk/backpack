#include "window_handler.h"
#include "terminal.h"
#include <ncurses.h>

WINDOW *WINDOW_COMMAND;
WINDOW *WINDOW_LINE_NUMBERS;
WINDOW *WINDOW_MAIN;

void windows_initialize() {
  refresh();
  WINDOW_COMMAND = newwin(1, COLUMNS, ROWS - 1, 0);
  WINDOW_LINE_NUMBERS = newwin(ROWS - 1, 3, 0, 0);
  WINDOW_MAIN = newwin(ROWS - 1, COLUMNS - 3, 0, 3);

  wbkgd(WINDOW_COMMAND, COLOR_PAIR(1));
  wbkgd(WINDOW_LINE_NUMBERS, COLOR_PAIR(2));
  wbkgd(WINDOW_MAIN, COLOR_PAIR(3));

  wrefresh(WINDOW_COMMAND);
  wrefresh(WINDOW_LINE_NUMBERS);
  wrefresh(WINDOW_MAIN);
}
