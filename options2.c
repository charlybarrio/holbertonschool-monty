#include "monty.h"

/**
 * add - function that swaps the top two elements of the stack
 * @head: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int len, result;

	for (len = 1; (head && (tmp)->next) && len < 2; len++)
		tmp = tmp->next;
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		buf_tok = NULL;
		return;
	}

	result = (*head)->n + ((*head)->next)->n;
	((*head)->next)->n = result;
	((*head)->next)->prev = NULL;
	pop(&(*head), line_number);
}

/**
 * nop - function that doesn’t do anything
 * @head: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
