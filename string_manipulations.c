#include "string_manipulations.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int modify_character(char *string, int size, int position, char character) {
  // Make sure the position is within bounds
  if (position >= 1 && position <= size) {
    string[position - 1] = character;
    return 1;
  } else {
    return -7;
  }
}

int remove_character(char *string, int size, int position) {
  // Make sure the position is within bounds
  if (position >= 1 && position <= size) {
    // Shift the characters to the left starting from said position
    for (int i = position - 1; i < size - 1; i++) {
      string[i] = string[i + 1];
    }
    string[size - 1] = '\0';
    return 1;
  } else {
    return -7;
  }
}

char *format_string(const char *format, ...) {
  // Initialize arguments after format
  va_list args;
  va_start(args, format);

  // Determine the required size to store formatted null terminated string
  int size = vsnprintf(NULL, 0, format, args) + 1;
  va_end(args);

  // Allocate memory for the formatted string
  char *buffer = (char *)malloc(size);

  if (buffer == NULL) {
    return "E6: Failed to allocate memory.";
  } else {
    va_start(args, format);
    // Write formatted string into the buffer
    vsnprintf(buffer, size, format, args);
    va_end(args);
  }

  return buffer;
}
