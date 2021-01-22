#include "lists.h"
/**
* is_palindrome - checks if a singly linked list is a palindrome
* @head: pointer of first node of listint_t list
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	if (head == NULL)
	{
		return (0);
	}
	return (check_pal(head, *head));
}

/**
* check_pal - checker function
* @left: pointer
* @right: pointer
* Return: result
*/
int check_pal(listint_t **left, listint_t *right)
{
	int temp;

	if (right == NULL)
	{
		return (1);
	}

	temp = check_pal(left, right->next);

	if (temp == 0)
	{
		return (0);
	}

	temp = (right->n == (*left)->n);

	*left = (*left)->next;

	return (temp);
}
