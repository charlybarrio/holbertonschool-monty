#include "monty.h"

/**
 * push - function thath prints the value at the top of the stack,
 * followed by a new line
 * @stack: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void push(stack_t **stack, unsigned int line_number)
{
	int tok_int = 0;

	buf_tok = strtok(NULL, DELIM);
	if (!buf_tok)
		goto end;
	if (!is_number(buf_tok) && buf_tok[0] == '-')
	{
end:
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		buf_tok = NULL;
		return;
	}
	tok_int = atoi(buf_tok);
	add_tostack(stack, tok_int);
}

/**
 * pall - function thath prints the value at the top of the stack,
 * followed by a new line
 * @stack: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}

/**
 * pop - Deletes a node
 * @head: Pointer to the top of the stack
 * @line_number: the current line read
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!head || !(*head))
	{
		dprintf(STDOUT_FILENO, "L%d: can't pop an empty stack\n", line_number);
		buf_tok = NULL;
		return;
	}
	node = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(node);
}

/**
 * pint - function thath prints the value at the top of the stack,
 * followed by a new line
 * @head: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head || !(*head))
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		buf_tok = NULL;
		return;
	}
	dprintf(STDOUT_FILENO, "%d\n", (*head)->n);
}

/**
 * swap - function that swaps the top two elements of the stack
 * @head: is a pointer to the top of the stack
 * @line_number: the current line read
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int len, n;

	for (len = 1; (tmp && (tmp)->next) && len < 2; len++)
		tmp = tmp->next;
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		buf_tok = NULL;
		return;
	}

	n = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = n;
}
