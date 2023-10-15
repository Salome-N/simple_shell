#include "main.h"

int tok_len(char *str, char *delim);
int count_tok(char *str, char *delim);

/**
* tok_len - counts the length of a token
* @str: string that contains tokens
* @delim: delimiter that separates tokens in str
* Return: token size
*/

int tok_len(char *str, char *delim)
{
	int i = 0, l = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		l++;
		i++;
	}

	return (l);
}

/**
* count_tok - counts no. of tokens int a string
* @str: string that cointains tokens
* @delim: delimiter that separates the tokens in str
* Return: no. of tokens in str
*/

int count_tok(char *str, char *delim)
{
	int i, tok = 0, l = 0;

	for (i = 0; *(str + i); i++)
		l++;

	for (i = 0; i < l; i++)
	{
		if (*(str + i) != *delim)
		{
			tok++;
			i += tok_len(str + i, delim);
		}
	}

	return (tok);
}

/**
* _strtok - splits string to tokens using a delimitor
* @str: string to be split into tokens
* @delim: delimiter that separates the tokens in str
* Return: pointer to the tokens
*/

char **_strtok(char *str, char *delim)
{
	char **ptr;
	int i = 0, tok, let, t, l;

	tok = count_tok(str, delim);
	if (tok == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tok + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tok; t++)
	{
		while (str[i] == *delim)
			i++;

		let = tok_len(str + i, delim);

		ptr[t] = malloc(sizeof(char) * (let + 1));
		if (!ptr[t])
		{
			for (i -= 1; i >= 0; i--)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < let; l++)
		{
			ptr[t][l] = str[i];
			i++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
