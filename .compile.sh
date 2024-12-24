#!/bin/bash

Output=".program"
Dependencies="-lncurses"

if [[ $# -ne 0 ]]; then
  Output=$1
fi

gcc -c $(ls *.c | xargs)
gcc *.o -o $Output $Dependencies
