#include "main.h"

/**
* _getenv - Searches fr the environment var specified
* @name: env variable
* Return: ptr to the start of the env var's value
*/

char *_getenv(char *name)
{
	int i = 0, l = _strlen(name);
	char *p = NULL;

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], l) == 0)
		{
			p = _strdup(environ[i] + l + 1);
			return (p);
		}
		i++;
	}

	return (NULL);
}

/**
* add_node - Adds new node to the start of the list
* @head: ptr to the head node address
* @str: strint to be added to the node
* Return: ptr to the created node
*/

dir_l *add_node(dir_l **head, char *str)
{
	dir_l *node = NULL;

	if (str == NULL)
		return (NULL);

	node = malloc(sizeof(dir_l));
	if (node == NULL)
		return (NULL);

	node->dir_path = strdup(str);
	if (*head == NULL)
	{
		node->nxt = NULL;
		*head = node;
	}
	else
	{
		node->nxt = *head;
		*head = node;
	}

	return (node);

}

/**
* free_list - frees memory on list
* @head: ptr to the head node address
* Return: void
*/

void free_list(dir_l *head)
{
	dir_l *nxt;

	while (head)
	{
		nxt = head->nxt;
		free(head->dir_path);
		free(head);
		head = nxt;
	}
}
