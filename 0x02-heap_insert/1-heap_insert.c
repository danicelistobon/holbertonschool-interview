#include <stdlib.h>
#include "binary_trees.h"
/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: double pointer to the root node of the Heap
* @value: value store in the node to be inserted
* Return: pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (root == NULL)
		return (NULL);

	parent = find_parent(*root);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent == NULL)
		*root = new;
	else if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	swap(&new);

	return (new);
}

/**
* find_parent - finds the parent
* @node: pointer to the node to check
* Return: pointer to the parent
*/
heap_t *find_parent(heap_t *node)
{
	int l_leaf, r_leaf, l_tree, r_tree;

	if (node == NULL)
		return (NULL);

	l_leaf = is_leaf(node->left);
	r_leaf = is_leaf(node->right);

	if (l_leaf < 1 || r_leaf < 1)
		return (node);

	l_tree = is_perfect(node->left);
	r_tree = is_perfect(node->right);

	if (l_tree < 1 || (l_tree && r_tree && l_leaf == r_leaf))
		return (find_parent(node->left));
	else if (r_tree < 1 || (l_tree && r_tree && l_leaf > r_leaf))
		return (find_parent(node->right));
	else
		return (node);
}

/**
* is_leaf - checks if a node is a leaf
* @node: pointer to the node to check
* Return: 1 if node is a leaf, otherwise 0
*/
int is_leaf(heap_t *node)
{
	int leafs;

	if (node == NULL)
		return (0);

	leafs = 1;

	leafs = leafs + is_leaf(node->left);
	leafs = leafs + is_leaf(node->right);

	return (leafs);
}

/**
* is_perfect - checks if a tree is perfect
* @node: pointer to the node to check
* Return: 1 if tree is perfect, otherwise 0
*/
int is_perfect(heap_t *node)
{
	int left, right;

	if (node == NULL)
		return (0);

	left = is_leaf(node->left);
	right = is_leaf(node->right);

	if (left == right)
		return (1);
	else
		return (0);
}

/**
* swap - swaps two values
* @node: pointer to the node
* Return: Nothing
*/
void swap(heap_t **node)
{
	heap_t *current;
	int value_aux;

	current = *node;

	while (current->parent != NULL)
	{
		if (current->parent->n < current->n)
		{
			value_aux = current->parent->n;
			current->parent->n = current->n;
			current->n = value_aux;
			*node = current->parent;
		}
		else
			current = current->parent;
	}
}

