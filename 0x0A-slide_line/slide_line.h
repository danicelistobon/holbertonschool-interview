#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void swap_ints(int *l, int *r);
void shift_left(int *line, size_t size);
void shift_right(int *line, size_t size);

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
#endif
