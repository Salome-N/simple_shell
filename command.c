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
		free(cmd);
		return (NULL);
	}

	if (cmd[read_b - 1] == '\n')
		cmd[read_b - 1] = '\0';

	fflush(stdin);

	return (cmd);
}

/**
* update_cmd - Updates a commmand arg
* @args: ptr to the argument array
* @index: index of the token command
* @arg: vslue of update argument
* Return: void
*/

void update_cmd(char **args, int index, char *arg)
{
	if (!args || !(*args) || !arg || index < 0)
		return;
	free(args[index]);
	args[index] = NULL;
	args[index] = _strdup(arg);
}
