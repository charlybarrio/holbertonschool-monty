#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main (__attribute__((unused)) int argc, char **argv)
{
	FILE *fp = NULL;
	char *line = NULL, **split_line = NULL;
	int line_number; /* variable for read line number */
	size_t len = 0;
	ssize_t read;
	void (*fun)(); /* variable for get the option function */
	stack_t *stack = NULL; /* double linked list (not implemented)*/

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	/* open the file with read permissions*/
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	/* read the file line per line */
	for (line_number = 1; (read = getline(&line, &len, fp)) != -1; line_number++)
	{
		/* tokenize current line */
		split_line = split(line, " \t\n");
		if (!split_line) /* check tokenize and print error if it fails */
		{
			dprintf(STDERR_FILENO, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		fun = op_fun(split_line); /* get the option function */
		if (!fun) /* check function return and print error if it fails*/
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction\n", line_number);
			fclose(fp);
			if (line) /* free memory of getline */
				free(line), line = NULL;
			exit(EXIT_FAILURE);
		}
		fun (&stack, line_number); /* execute the function return */
		/* free memory and set to NULL for nexts iterations */
		free(split_line), split_line = NULL;
	}
	fclose(fp);
	if (line)
		free(line), line = NULL;
	exit(EXIT_SUCCESS);
}

void push(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	printf("push-fun\n");
}
void pall(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	printf("pall-fun\n");
}
void printerror()
{
}
