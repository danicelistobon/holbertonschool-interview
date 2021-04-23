#include "sort.h"
/**
* heap_sort - sorts an array of integers in ascending order using the Heap sort
* @array: array to be sorted
* @size: number of elements
*/
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		build(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		build(array, i, 0, size);
	}
}

/**
* build - builds heap
* @array: array
* @n: size
* @i: index
* @size: number of elements
*/
void build(int *array, int n, int i, size_t size)
{
	int max = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < n && array[left] > array[max])
	{
		max = left;
	}
	if (right < n && array[right] > array[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		build(array, n, max, size);
	}
}

/**
* swap - swaps elements
* @i: element
* @j: element
*/
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
