#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

#include <ncurses.h>

extern WINDOW *WINDOW_COMMAND;
extern WINDOW *WINDOW_LINE_NUMBERS;
extern WINDOW *WINDOW_MAIN;

extern void windows_initialize();

#endif
