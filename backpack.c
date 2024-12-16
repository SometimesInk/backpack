#include <ncurses.h>
#include <string.h>

int parse_command();
int parse_input(int input);
int get_input(int *holder);

static enum Modes {
  NORMAL,
  COMMAND,
} CURRENT;

const char *modeToString(enum Modes mode) {
  switch (mode) {
  case NORMAL:
    return "NORMAL";
  case COMMAND:
    return "COMMAND";
  default:
    return "Unknown";
  }
}

static char NORM_ENTRY[100];
static char COMM_ENTRY[100];

int main() {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  while (get_input(&ch) && parse_input(ch))
    ;

  refresh();
  endwin();

  return 0;
}

int parse_input(int input) {
  switch (input) {
  case 'q':
    return 0;
  case 58: // Semi-colon
    if (CURRENT != COMMAND)
      CURRENT = COMMAND;
    break;
  case 10: // Enter key
    if (CURRENT == COMMAND)
      parse_command();
  }
  mvprintw(0, 0, "Mode: %s & Input: %c & Numberic: %i      ok?",
           modeToString(CURRENT), input, input);
  return 1;
}

int get_input(int *holder) {
  *holder = getch();
  return 1;
}

int parse_command() {
  char buffer[100];
  strncpy(buffer, COMM_ENTRY, sizeof(buffer));

  char *command = strtok(buffer, " ");
  char *arguments = strtok(NULL, "");

  return 1;
}
