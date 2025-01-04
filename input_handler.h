#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

/// All characters typed while in COMMAND_MODE
extern char COMMAND_INPUT[100];

/// A cursor representing where to write to COMMAND_INPUT
extern int COMMAND_USED_INPUT;

/// Sets the value of the output variable to the keycode of the pressed key
/// Returns:
///   1 --> Success
extern int get_input(int *output);

/// Returns:
///   1 --> Success
extern int parse_key(int input);

/// Returns:
///   1 --> Success
///   2 --> Call parse_command()
extern int parse_key_command(int input);

#endif
