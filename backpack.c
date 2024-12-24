#include "input_handler.h"
#include "main_handler.h"
#include <ncurses.h>
#include <stdlib.h>

int main() {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  while (get_input(&ch) && handle(ch))
    ;

  endwin();
  return EXIT_SUCCESS;
}
