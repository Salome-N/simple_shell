#include "main.h"

/**
* exe_cmd - searches for executables in the sys path
* @args: array of strings containing cmd and args
* @env: ptr to array of strings of env variables
* Return: void
*/

int exe_cmd(char **args, char **env)
{
	pid_t c_pid;
	char *prg_path = prg_search(args[0]);
	int status;

	if (prg_path == NULL)
	{
		perror("null prg_path");
		return (-1);
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

	free(prg_path);
	return (1);
}
