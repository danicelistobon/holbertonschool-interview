#include "search_algos.h"
/**
* advanced_binary - searches for a value in a sorted array of integers
* @array: pointer to the first element of the array
* @size: number of elements in array
* @value: value to search for
* Return: index where value is located, if value is not present in array or if
* array is NULL, your function must return -1
**/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
	{
		return (-1);
	}
	return (recursive(array, 0, size - 1, value));
}

/**
* recursive - recursive function to searche for a value
* @array: pointer
* @left: pointer
* @right: pointer
* @value: value to search for
* Return: index where value is located
**/
int recursive(int *array, int left, int right, int value)
{
	int mid;

	print(array, left, right);

	mid = (right - left) / 2 + left;

	if (left == right)
	{
		return (-1);
	}
	if (array[mid] == value && array[mid - 1] != value)
	{
		return (mid);
	}
	if (array[mid] >= value)
	{
		return (recursive(array, left, mid, value));
	}
	if (array[mid] <= value)
	{
		return (recursive(array, mid + 1, right, value));
	}
	return (-1);
}

/**
* print - prints an array
* @array: pointer
* @left: pointer
* @right: pointer
**/
void print(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");

	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}
