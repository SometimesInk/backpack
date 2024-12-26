#include "terminal.h"
#include <ncurses.h>

int ROWS, COLUMNS;

void terminal_initialize() { getmaxyx(stdscr, ROWS, COLUMNS); }
