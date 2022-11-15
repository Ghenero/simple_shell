#include "main.h"

/**
 * read_line - read input form user stdin
 * Return: string entered
 */

char *read_line()
{
	size_t len;
	char *buff = NULL;
	int i;

	getline(&buff, &len, stdin);
	for (i = 0; buff[i] != '\n'; i++)
		;
	buff[i + 1] = '\0';
	return (buff);
}
