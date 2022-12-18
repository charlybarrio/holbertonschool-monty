#include "main.h"

/**
 * main - main function
 * @argc: count arguments
 * @argv: argument passed
 *
 * Return: EXIT_SUCCESS and EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	int line_number; /* variable for read line number */
	char *line = NULL;
	FILE *file_p = NULL;
	stack_t *stack = NULL; /* double linked list for stack */
	void (*fun)(); /* variable for get the option function */

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n"),
			exit(EXIT_FAILURE);
	}
	/* open the file with read permissions*/
	file_p = fopen(argv[1], "r");
	if (!file_p)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
				argv[1]), exit(EXIT_FAILURE);
	}
	/* read the file line per line */
	for (line_number = 1; (getline(&line, &len, file_p)) != -1; line_number++)
	{
		buf_tok = strtok(line, DELIM);
		if (!buf_tok)
			continue;
		fun = get_opfun(buf_tok); /* get the option function */
		if (!fun) /* check function return and print error if it fails*/
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction\n", line_number);
			/* free all memory alocated and exit */
			freezerr(&file_p, &stack, &line, EXIT_FAILURE);
		}
		fun(&stack, line_number); /* execute the function return */
		if (buf_tok == NULL)
			freezerr(&file_p, &stack, &line, EXIT_FAILURE);
	}
	freezerr(&file_p, &stack, &line, EXIT_SUCCESS);
	return (0);
}
