#include "monty.h"

/**
 * add_dnodeint - add node at beginning of list
 * @head: pointer to pointer
 * @n: int data to be added
 * Return: pointer to new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
	return (new_node);
}
