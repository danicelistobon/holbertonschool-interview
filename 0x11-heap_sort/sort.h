#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void build(int *array, int m, int i, size_t size);
void swap(int *i, int *j);

#endif
