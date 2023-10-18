#include "main.h"

void shell_exit(char **args);
void free_args(char **args);

/**
* exe_cmd - searches for executables in the sys path
* @args: array of strings containing cmd and args
* @env: ptr to array of strings of env variables
* Return: void
*/

int exe_cmd(char **args, char **env)
{
	pid_t c_pid;
	char *prg_path = args[0];
	int status;

	if (prg_path == NULL)
	{
		perror("null prg_path");
		return (1);
	}

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (c_pid == 0)
	{
		if (execve(prg_path, args, env) == -1)
		{
			perror(prg_path);
			return (-1);
		}
	}
	else
	{
		waitpid(c_pid, &status, 0);
	}

	return (1);
}

/**
* shell_exit - exits the shell
* @args: array of words inputed in shell
* Return: void
*/

void shell_exit(char **args)
{
	int exit_c = 0;

	if (args[1])
	{
		exit_c = atoi(args[1]);
		if (exit_c < 0)
		{
			exit_c = 2;
		}
	}

	free_args(args);
	printf("[Disconnected...]\n");
	exit(exit_c);
}

/**
* free_args - frees array of strings
* @args: address to ptr to an array of strings
* Return: void
*/

void free_args(char **args)
{
	int n;

	if (args == NULL)
		return;

	n = 0;
	while (args[n] != NULL)
		free(args[n++]);

	free(args);
	args = NULL;
}
