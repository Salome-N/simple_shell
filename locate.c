#include "main.h"

/**
* get_dir_path - tokenize string of directory list to a linked list
* @path: string of directory list
* Return: ptr to linked list
*/

dir_l *get_dir_path(char *path)
{
	int i;
	char *dir;
	dir_l *head = NULL;

	dir = strtok(path, ":");
	if (!dir)
		return (NULL);

	for (i = 0; dir; i++)
	{
		if (add_node(&head, dir) == NULL)
		{
			free_list(head);
			free(dir);
			return (NULL);
		}
		dir = strtok(NULL, ":");
	}
	free(dir);

	return (head);
}

/**
* isPrgPath - checks if path is specified is the path to prg
* @path: path to the program
* Return: path
*/

int isPrgPath(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

/**
* file_search - searches for a file in dir_l list
* @head: ptr to dir_l list
* @name: file name
* Return: ptr to file path string
*/

char *file_search(dir_l *head, char *name)
{
	char *f = NULL;
	int file_l = 0, dir_l = 0;
	int name_l = _strlen(name);

	if (head == NULL || name == NULL)
		return (NULL);

	while (head != NULL)
	{
		dir_l = _strlen(head->dir_path);
		file_l = dir_l + name_l + 2;
		f = malloc(sizeof(*f) * file_l);

		if (!f)
			return (NULL);

		_memcpy(f, head->dir_path, dir_l);
		_memcpy(f + dir_l, "/", 1);
		_memcpy(f + dir_l + 1, name, name_l);
		f[file_l - 1] = '\0';

		if (isPrgPath(f))
			return (f);
		free(f);
		f = NULL;
		head = head->nxt;
	}

	return (NULL);
}

/**
* prg_search - searches for a program in the process env
* @name: name of the program
* Return: ptr to the updated program name token
*/

char *prg_search(char *name)
{
	char *path = _getenv("PATH");
	char *prg_path = NULL;
	dir_l *head = NULL;

	if (!name || !path)
		return (NULL);

	if (isPrgPath(name))
	{
		free(path);
		return (_strdup(name));
	}

	head = get_dir_path(path);
	prg_path = file_search(head, name);

	if (prg_path == NULL)
	{
		free_list(head);
		free(path);
		return (NULL);
	}

	free_list(head);
	free(path);
	return (prg_path);
}
