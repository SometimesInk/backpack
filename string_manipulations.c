#include "string_manipulations.h"

int modify_character(char *string, int size, int position, char character) {
  // Make sure the position is within bounds
  if (position >= 1 && position <= size) {
    string[position - 1] = character;
    return 1;
  } else {
    return -1;
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
    return -1;
  }
}
