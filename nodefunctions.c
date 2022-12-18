#include "main.h"

/**
 * add_tostack - Function that adds a new node at the
 * beginning of a list.
 * @head: The pointer to the list.
 * @n: Int for the new node set.
 *
 * Return: The newnode.
 */
stack_t *add_tostack(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = makenode(n);
	if (!newnode)
	{
		free(newnode);
		return (NULL);
	}
	if (!*head)
		*head = newnode;
	else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
	return (newnode);
}

/**
 * makenode - Function that create a new node for an list
 * @n: The integer to set in the new node.
 *
 * Return: The new node.
 */
stack_t *makenode(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
/**
 * free_stack - Function that frees a list.
 * @head: is the listint_t to free.
 *
 */
void free_stack(stack_t *head)
{
	if (head)
	{
		free_stack(head->next);
		free(head);
	}
}

