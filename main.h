#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

#define UN_ATTR __attribute__((unused))

extern char **environ;

/**
* struct dir_list - definition for a node in linked list
* @dir_path: directory path
* @nxt: ptr to the next node
*/

typedef struct dir_list
{
	char *dir_path;
	struct dir_list *nxt;
} dir_l;

/** Main Functions **/

void prompt(void);
char *read_cmd(void);
char **str_split(char *str, int *argc);
void update_cmd(char **args, int index, char *arg);

/** Environment **/

char *_getenv(char *name);
dir_l *add_node(dir_l **head, char *str);
void free_list(dir_l *head);
dir_l *get_dir_path(char *path);
char *file_search(dir_l *head, char *name);
int isPrgPath(char *path);
char *prg_search(char *name);

/** Execute Functions **/
int exe_cmd(char **args, char **env);
void shell_exit(char **args);
void env_print(void);
void free_args(char **args);
void free_args2(char ***args);

/** UTILS **/
int _atoi(const char *str);
int _strncmp(const char *s1, char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *src);
void cleanup(UN_ATTR char *cmd,
UN_ATTR char **args, UN_ATTR char *prgpath);

#endif
