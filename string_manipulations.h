#ifndef STRING_MANIPULATIONS_H
#define STRING_MANIPULATIONS_H

/// Modifies the Nth character of a string to another
/// Returns:
///  -7 --> Index is out of bounds
///   1 --> Success
extern int modify_character(char *string, int size, int position,
                            char character);

/// Removes the Nth character of a string
/// Returns:
///  -7 --> Index is out of bounds
///   1 --> Success
extern int remove_character(char *string, int size, int position);

extern char *format_string(const char *string, ...);
#endif
