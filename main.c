#include "main.h"

/**
 * main - implement simple commmand line interpreter
 * @ac: length of arguments passed
 * @av: list of parsed argument
 * Return: Always 0.
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *str = NULL;
	int exit = 1;
	char **tokens;

	/*printf("argc: %i\n argv[0]: %s", argc, argv[0]);*/

	if (!isatty(STDIN_FILENO))
	{
		/* perform operation with str value*/
		str = read_line();
		printf("%s", str);
		return (0);
	}

	while (exit)
	{
		write(STDOUT_FILENO, "~$ ", 3);
		str = read_line();
		/*printf("%s", str);*/
		/*handle_tokens(str);*/
		tokens = get_tokens(str);
		/*
		 *while (tokens[i] != NULL)
		 *{
		 *	printf("%s.\n", tokens[i]);
		 *	i++;
		 *}
		 *i = 0;
		 */
		if (tokens[0] != NULL)
			exit = token_oven(tokens);
	}
	free(str);
	return (0);
}
