#include "main.h"

/**
 *cmd_launch - Launch a program and wait for it to terminate.
 *@args: Null terminated list of arguments (including program).
 *
 *Return: Always 1, to continue execution.
 */
int cmd_launch(char **args)
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
#ifdef HSH_USE_STD_GETLINE
	char *line = NULL;
	ssize_t bufsize = 0; /* have getline allocate a buffer for us */

	getline(&line, &bufsize, stdin);
	return (line);
#else
#define HSH_RL_BUFSIZE 1024
	int bufsize = HSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read a character */
		c = getchar();

		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		/* If we have exceeded the buffer, reallocate. */
		if (position >= bufsize)
		{
			bufsize += HSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}

/**
 *hsh_split_line - Split a line into tokens (very naively).
 *@line: The line.
 *
 *Return: Null-terminated array of tokens.
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
 *hsh_loop - Loop getting input and executing it.
 */
void life_cycle(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = get_tokens(line);
		status = cmd_execute(args);

		free(line);
		free(args);
	} while (status);
}
