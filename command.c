#include "main.h"

/**
* prompt - prompts the user to enter a command
* Return: void
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
* read_cmd - reads the input command
* Return: command
*/

char *read_cmd(void)
{
	char *cmd = NULL;
	ssize_t read_b;
	size_t cmd_l = 0;

	read_b = getline(&cmd, &cmd_l, stdin);

	if (read_b == -1)
	{
		if (read_b == EOF)
		{
			free(cmd);
			return (NULL);
		}
		perror("Readcmd");
		free(cmd);
		return (NULL);
	}

	if (cmd[read_b - 1] == '\n')
		cmd[read_b - 1] = '\0';

	fflush(stdin);

	return (cmd);
}
