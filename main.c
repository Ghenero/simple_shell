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
