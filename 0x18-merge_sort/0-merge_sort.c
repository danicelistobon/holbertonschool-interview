#include "sort.h"

/**
* merge_sort - sorts an array of integers in ascending order using
* the Merge Sort algorithm
* @array: array of integers
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *subarray;
	size_t i = 0;

	if (!array || size < 2)
	{
		return;
	}

	subarray = malloc(size * sizeof(int));

	if (!subarray)
	{
		return;
	}

	for (; i < size; i++)
	{
		subarray[i] = array[i];
	}

	merge_split(array, subarray, 0, size);
	free(subarray);
}

/**
* merge_split - recursive function
* @array: array
* @subarray: copy of the array
* @left: begin of the array
* @right: end of the array
*/
void merge_split(int *array, int *subarray, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (right - left <= 1)
	{
		return;
	}

	merge_split(subarray, array, left, mid);
	merge_split(subarray, array, mid, right);
	merge(array, subarray, left, right, mid);
}

/**
* merge - merges the array
* @array: array
* @subarray: copy of the array
* @left: begin of the array
* @right: end of the array
* @mid: middle of left and right
*/
void merge(int *array, int *subarray, int left, int right, int mid)
{
	int start, end, i = left;

	start = left;
	end = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(subarray + left, mid - left);
	printf("[right]: ");
	print_array(subarray + mid, right - mid);

	while (start < mid && end < right)
	{
		if (subarray[start] < subarray[end])
		{
			array[i] = subarray[start];
			start++;
		}
		else
		{
			array[i] = subarray[end];
			end++;
		}
		i++;
	}
	while (start < mid)
	{
		array[i] = subarray[start];
		i++;
		start++;
	}
	while (end <= right)
	{
		array[i] = subarray[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}
