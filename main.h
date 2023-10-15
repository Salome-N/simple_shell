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
char **_strtok(char *str, char *delim);

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

#endif
