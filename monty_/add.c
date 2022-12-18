#include "monty.h"
/**
 * add - adds elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: the number of the line it the file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int sm;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	sm = new->n + new->next->n;
	new->next->n = sm;
	*stack = new->next;
	free(new);
}
