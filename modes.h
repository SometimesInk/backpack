#ifndef MODES_H
#define MODES_H

typedef enum { NORMAL, COMMAND } Mode;

extern Mode CURRENT_MODE;

const char *mode_as_string(Mode mode);

#endif
