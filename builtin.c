#include "main.h"

/**
* env_print - prints the current env
* variables and returns as string
*/

void env_print(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
