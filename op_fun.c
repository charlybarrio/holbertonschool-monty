#include "main.h"

void (*op_fun(char **split_line))()
{
	instruction_t options[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int index;

	for (index = 0; options[index].opcode; index++)
	{
		if (strcmp(split_line[0], options[index].opcode) == 0)
		{
			return (options[index].f);
		}
	}
	return (NULL);
}
