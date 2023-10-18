#include "main.h"

/**
* cleanup - Free the dynamically allocated memory for the command, arguments,
* and program path.
* @cmd: commands to be freed
* @prgpath: path to free
* @args: ...
* Return: nothing
*/

void cleanup(UN_ATTR char *cmd,
UN_ATTR char **args,
UN_ATTR char *prgpath)
{
	if (cmd)
		free(cmd);
	if (args)
		free_args2(&args);
	if (prgpath)
		free(prgpath);
}

/**
* main - runs the sumple UNIX cmd line interpreter
* @argc: no. of arguments
* @argv: array of ptrs to arguments
* @env: ptr to an array of env var
* Return: void
*/

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *cmd, **args = NULL, *prg_path = NULL;
	int num_args = 0;

	while (1 && argv[0])
	{
		prompt();
		cmd = read_cmd();
		if (cmd == NULL)
			break;
		args = str_split(cmd, &num_args);
		if (_strcmp(args[0], "exit") == 0)
		{
			cleanup(cmd, args, prg_path);
			shell_exit(args);
		}
		else if (_strcmp(args[0], "env") == 0)
			env_print();
		else
		{
			prg_path = prg_search(args[0]);
			if (prg_path != NULL)
			{
				update_cmd(args, 0, prg_path);
				exe_cmd(args, env);
			}
		}
		cleanup(cmd, args, prg_path);
	}
	return (EXIT_SUCCESS);
}
