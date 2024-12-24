#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

extern char NORMAL_INPUT[100];
extern char COMMAND_INPUT[100];
extern int normal_used_input;
extern int command_used_input;

extern int get_input(int *holder);

extern int parse_key(int input);

extern int modify_character(char *string, int size, int position,
                            char character);
extern int remove_character(char *string, int size, int position);

#endif
