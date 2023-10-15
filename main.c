#include "main.h"

/**
* main - runs the sumple UNIX cmd line interpreter
* @argc: no. of arguments
* @argv: array of ptrs to arguments
* @env: ptr to an array of env var
* Return: void
*/

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *cmd;
	char **args = NULL;

	while (1 && argv[0])
	{
		prompt();
		cmd = read_cmd();
		args = _strtok(cmd, " ");
		exe_cmd(args, env);
		free(cmd);
	}

	return (EXIT_SUCCESS);
}
