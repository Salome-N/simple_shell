#include "main.h"

#define MAX_TOKENS 100
#define DELIMS " \t\r\n"

/**
* str_split - a function that tokenizes input to the shell
* @str: input string with command and arguments
* @argc: counts the number of arguments
* Return: toks
*/

char **str_split(char *str, int *argc)
{
	char **toks = malloc(MAX_TOKENS * sizeof(char *));
	char *token;
	int token_position = 0;

	if (toks == NULL)
	{
		perror("split string: failed to allocate memory for toks");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, DELIMS);
	while (token != NULL)
	{
		if (token_position >= MAX_TOKENS)
		{
			perror("split_string: too many toks, limit is 100");
			exit(EXIT_FAILURE);
		}
		if (token[0] == '"' && token[_strlen(token) - 1] == '"')
		{
			token[_strlen(token) - 1] = '\0';
			token++;
		}
		toks[token_position] = _strdup(token);

		if (!toks[token_position])
		{
			while (token_position > 0)
				free(toks[--token_position]);
			free(toks);
			return (NULL);
		}
		token_position++;
		token = strtok(NULL, DELIMS);
	}
	toks[token_position] = NULL;
	*argc = token_position;

	return (toks);
}
