#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
* insert_node - inserts a number into a sorted singly linked list
* @head: pointer
* @number: integer
* Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		current = *head;

		while (current->next != NULL && current->next->n < new->n)
			current = current->next;

		new->next = current->next;
		current->next = new;
	}
	return (new);
}
