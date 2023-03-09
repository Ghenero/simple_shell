#include "main.h"

/**
 *run_command - Launch a program and wait for it to terminate.
 *@args: Null terminated list of arguments (including program).
 *
 *Return: Always 1, to continue execution.
 */
int run_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("PID = -1");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror(args[0]);
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 *read_line - Read a line of input from stdin.
 *
 *Return: The line from stdin.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1){
		if (feof(stdin)) {
			exit(EXIT_SUCCESS);
		} else  {
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return line;
}

/**
 * get_tokens - Split a line into tokens (very naively).
 * @line: one line of string.
 *
 * Return: Null-terminated array of tokens.
 */
char **get_tokens(char *line)
{
	int bufsize = HSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, HSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += HSH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, HSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
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
