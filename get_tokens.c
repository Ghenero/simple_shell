#include "main.h"
/**
 * get_tokens - get tokens form stringpointers
 * @src: source of string
 * Return: nothing
 */

char **get_tokens(char *src)
{
	int counter = 0, tokCnt = 0;
	char **tokens;
	const char delim = 32;

	tokens = malloc(sizeof(char *) * 20);
	while (src[counter] != '\n')
	/*set condition for token*/
	{
		if (counter > 0)
		{
			if (src[counter] != delim && src[counter - 1] == delim)
			{
				/*new token found*/
				*(tokens + tokCnt) = &src[counter];
				tokCnt++;
				src[counter - 1] = '\0';
			}
			if (src[counter] == delim)
			{
				if (src[counter + 1] == delim || src[counter + 1] == '\n')
				{
					src[counter] = '\0';
				}
			}
		}
		else if (counter == 0)
		{
			if (src[counter] != delim)
			{
				/*first token found*/
				*(tokens + tokCnt) = &src[counter];
				tokCnt++;
			}
		}
		counter++;
	}
	src[counter] = '\0';
	*(tokens + tokCnt) = NULL;
	return (tokens);
}
