#include "window_handler.h"
#include "terminal.h"
#include <ncurses.h>

WINDOW *COMMAND_WINDOW;
WINDOW *LINE_NUMBERS_WINDOW;
WINDOW *MAIN_WINDOW;

void initialize_windows() {
  refresh();
  COMMAND_WINDOW = newwin(1, COLUMNS, ROWS - 1, 0);
  LINE_NUMBERS_WINDOW = newwin(ROWS - 1, 3, 0, 0);
  MAIN_WINDOW = newwin(ROWS - 1, COLUMNS - 3, 0, 3);

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_RED);

  wbkgd(COMMAND_WINDOW, COLOR_PAIR(1));
  wbkgd(LINE_NUMBERS_WINDOW, COLOR_PAIR(2));
  wbkgd(MAIN_WINDOW, COLOR_PAIR(3));

  wrefresh(COMMAND_WINDOW);
  wrefresh(LINE_NUMBERS_WINDOW);
  wrefresh(MAIN_WINDOW);
}
