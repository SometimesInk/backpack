#ifndef MODES_H
#define MODES_H

typedef enum { MODE_NORMAL, MODE_COMMAND } Mode;

extern Mode MODE_CURRENT;

const char *mode_as_string(Mode mode);

/// Clear parameter values:
///   0 --- Will clear COMMAND_INPUT, COMMAND_WINDOW and command symbol
///   1 --- Will clear COMMAND_INPUT and command symbol
///   2 --- Will clear COMMAND_WINDOW, and command symbol
///   3 --- Will clear command symbol
///   4 --- Will clear all and command symbol will be added
typedef enum {
  /// 0 --- Will clear COMMAND_INPUT, COMMAND_WINDOW and command symbol
  EXIT_COMMAND_MODE_CLEAR_ALL,
  /// 1 --- Will clear COMMAND_INPUT and command symbol
  EXIT_COMMAND_MODE_CLEAR_INPUT,
  /// 2 --- Will clear COMMAND_WINDOW and command symbol
  EXIT_COMMAND_MODE_CLEAR_WINDOW,
  /// 3 --- Will clear command symbol
  EXIT_COMMAND_MODE_CLEAR_SYMBOL,
  /// 4 --- Will clear all and command symbol will be added
  EXIT_COMMAND_MODE_CLEAR_ALL_ADDITIVE
} Exit_Command_Mode_Clear;

/// Clears a certain part of the command system, and writes (or not) a message
/// to the COMMAND_WINDOW
///
/// Write parameter values:
///   0 --- Don't write
///   1 --- Write message
extern int exit_command_mode(Exit_Command_Mode_Clear clear, int write,
                             char *message);

#endif
