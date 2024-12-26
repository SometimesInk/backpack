#include "terminal.h"
#include <ncurses.h>

int ROWS, COLUMNS;

void initialize_terminal() { getmaxyx(stdscr, ROWS, COLUMNS); }
