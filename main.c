#include "main.h"

/**
 *Main - Main entry point to program.
 *@argc: Argument count.
 *@argv: Argument vector.
 *Return: status code
 */
int main(int argc, char *argv[])
{

	if (argc > 0 && argv[0] != NULL)
		life_cycle();
	else
		life_cycle();

	return (EXIT_SUCCESS);
}

/**
 * life_cycle - Loop getting input and executing it.
 * Return: void
 */
void life_cycle(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_line();
		args = get_tokens(line);
		status = cmd_execute(args);

		free(line);
		free(args);
	} while (status);
}
