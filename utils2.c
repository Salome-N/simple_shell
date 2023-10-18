#include "main.h"

/**
* _strncmp - Compare n bytes from two string
* @s1: The first string
* @s2: The second string
* @n: The number of bytes to compare
* Return: 0 if the strings exaclty match upto the nth byte
*/

int _strncmp(const char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] < s2[i] ? -1 : 1);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
* _strncpy - a function that copies from src to dest
* @src: source file
* @dest: destination file
* @n: copy limit
* Return: pointer to destinatiom
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
* _strcpy - Copies the source string to the destination buffer
* @dest: Destination buffer
* @src: Source string
* Return: Pointer to the destination buffer
*/

char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}

/**
* _atoi - Converts a string to an integer
* @str: The string to be converted
* Return: The converted integer
*/

int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			break;
		}
	}

	return (sign * result);
}

/**
* free_args2 - De-allocates memory from an array of strings
* allocated dynamically
* @args: the address of a pointer to an array of strings
* Return: void
*/

void free_args2(char ***args)
{
	int i;
	char **current_arg;

	if (args == NULL || *args == NULL)
		return;
	current_arg = *args;
	i = 0;
	while (current_arg[i] != NULL)
		free(current_arg[i++]);
	free(*args);
	*args = NULL;
}
