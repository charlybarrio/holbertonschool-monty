#include "monty.h"
/**
 * _pop - removes the top element of the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	start = *stack;
	if (!*stack)
	{
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
	}
	start = NULL;
	*stack = (*stack)->next;/*en lugar de esto podemos hacer que este vuelva al anterior*/ 
	free(start);
}
