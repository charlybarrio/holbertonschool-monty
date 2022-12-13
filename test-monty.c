#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main (__attribute__((unused)) int argc, char **argv)
{
	FILE *fp = NULL;
	char *line = NULL;
	char **split_line = NULL;
	int index;
	size_t len = 0;
	ssize_t read;

	if (argc < 1)
	{
		printf("USAGE: monty file");
		return (1);
	}

	/* read the file 00.m */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Retrieved line of length %ld:\n", read);
		printf("%s", line);
		split_line = split(line, " \t\n");
		printf("-- TOKENIZE-STR --\n");
		for (index = 0; split_line[index]; index++)
			printf("%s\n", split_line[index]);
		printf("-- TOKENIZE-END --\n");
		free(split_line), split_line = NULL;
	}
	fclose(fp);
	if (line)
		free(line), line = NULL;
	exit(EXIT_SUCCESS);
}

