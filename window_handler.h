#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

#include <ncurses.h>

extern WINDOW *COMMAND_WINDOW;
extern WINDOW *LINE_NUMBERS_WINDOW;
extern WINDOW *MAIN_WINDOW;

extern void initialize_windows();

#endif
