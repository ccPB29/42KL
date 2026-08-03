#!/bin/bash
gcc -W -W -W -c *.c
ar rcs libft.a *.o
rm -f *.o