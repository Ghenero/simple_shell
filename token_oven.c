#include "main.h"
/**
 * token_oven - executes command with given token.
 * @tokens: double pointer of tokens to execute
 * Return: 1 if ok or -1 on error
 */

int token_oven(char **tokens)
{
	pid_t pid;
	int result;

	pid = fork();
	/*conditioning pid output*/
	if (pid == -1)
	{
		perror("PID = -1");
		return (-1);
	}
	if (pid == 0)
	{
		result = execve(tokens[0], tokens, NULL);
		if (result == -1)
		{
			perror(tokens[0]);
			return (-1);
		}
	}
	else
	{
		wait(NULL);
		/*printf("done");*/
	}
	return (1);
}
