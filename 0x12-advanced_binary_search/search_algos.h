#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int recursive(int *array, int left, int right, int value);
void print(int *array, size_t left, size_t right);

#endif