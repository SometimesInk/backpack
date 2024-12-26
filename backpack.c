#include "input_handler.h"
#include "main_handler.h"
#include "terminal.h"
#include "window_handler.h"
#include <ncurses.h>
#include <stdlib.h>

int main() {
  int ch;

  // Initialize ncurses
  initscr();

  raw();
  keypad(stdscr, TRUE);
  noecho();

  if (!has_colors()) {
    printw("E3: Terminal has no colors");
    getch();
    endwin();
    return EXIT_SUCCESS;
  }

  // Initialize terminal and windows
  initialize_terminal();
  initialize_windows();

  while (get_input(&ch) && handle(ch))
    ;

  endwin();
  return EXIT_SUCCESS;
}
