#include "main.h"

char *built_in_str[] = {"cd", "help", "exit"};

/* list of function pointers to builtin commands function*/
int (*built_in_func[]) (char **) = {&cmd_cd, &cmd_help, &cmd_exit};

/**
 * built_in_counts - Calculates sizeof array containing builtins.
 * Return: int size of array
 */
int built_in_count(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * cmd_execute - Execute shell built-in or launch program
 * @args: Null terminated list of arguments.
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int cmd_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < built_in_count(); i++)
	{
		if (strcmp(args[0], built_in_str[i]) == 0)
		{
			return ((built_in_func[i])(args));
		}
	}

	return (launch_cmd(args));
}

/**
 * cmd_cd - function for cd command
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: Always returns 1, to continue executing.
*/
int cmd_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cmd");
		}
	}
	return (1);
}

/**
 * cmd_help - Builtin command: print help.
 * @args: List of args.
 * Return: Always returns 1
 */
int cmd_help(char **args)
{
	int i;

	if (args[0] != NULL)
		printf("Alx George and Nero simple shell Shell for linux\n");
	printf("The following are built in commands:\n");

	for (i = 0; i < built_in_count(); i++)
	{
		printf("  %s\n", built_in_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * hsh_exit - Builtin command: exit.
 * @args: List of args.  Non expected
 * return: Always returns 0, to terminate execution.
 */
int cmd_exit(char **args)
{
	if (args[0] == NULL)
		return (0);
	else
		return (0);
}
