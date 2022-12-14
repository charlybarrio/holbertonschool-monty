#include "main.h"

char **split(char *str, char *delim)
{
	char **split_str = NULL, *buf = NULL, *str_dup = NULL;
	int len, index;

	if (!str && !delim)
		return (NULL);

	str_dup = strdup(str);
	if (!str_dup)
		return (NULL);
	buf = strtok(str_dup, delim);
	for (len = 0; buf; len++)
		buf = strtok(NULL, delim);

	free(str_dup), str_dup = NULL;
	split_str = malloc(sizeof(char *) * len + 1);
	if (!split_str)
		return (NULL);
	buf = strtok(str, delim);
	for (index = 0; index < len; index++)
	{
		split_str[index] = buf;
		buf = strtok(NULL, delim);
	}
	split_str[index] = NULL;
	return (split_str);
}
