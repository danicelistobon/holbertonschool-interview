#ifndef MERGE_S
#define MERGE_S

#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void merge_split(int *array, int *subarray, int left, int right);
void merge(int *array, int *subarray, int left, int right, int mid);
void print_array(const int *array, size_t size);

#endif
