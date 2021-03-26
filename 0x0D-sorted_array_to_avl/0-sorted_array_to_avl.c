#include "binary_trees.h"

/**
* sorted_array_to_avl - builds an AVL tree from an array
* @array: pointer to the first element of the array to be converted
* @size: number of element in the array
* Return: pointer to the root node of the created AVL tree, or NULL on failure
**/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (!array)
			return (NULL);
		return (bisearch(array, 0, size - 1, NULL));
}

/**
* bisearch - build a tree
* @array: pointer
* @start: pointer
* @end: pointer
* @parent: parent node
* Return: pointer
**/
avl_t *bisearch(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
		node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	node->n = array[mid];
	node->parent = parent;
	node->left = bisearch(array, start, mid - 1, node);
	node->right = bisearch(array, mid + 1, end, node);
	return (node);
}
