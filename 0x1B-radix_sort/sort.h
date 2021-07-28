#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void radix_sort(int *array, size_t size);
int current_digit_sort(int *array, ssize_t size, int *tmp, long exp);
void print_array(const int *array, size_t size);

#endif
