#include "monty.h"

/**
 * get_opfun - function that find opfunction
 * @buf_tok: is the option to find
 *
 * Return: the function if found, NULL if faill
 */
void (*get_opfun(char *buf_tok))()
{
	instruction_t options[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};
	int index;

	for (index = 0; options[index].opcode; index++)
	{
		if (strcmp(buf_tok, options[index].opcode) == 0)
			return (options[index].f);
	}
	return (NULL);
}
