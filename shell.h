#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/**
 * struct builtin - Struct builtin
 *
 * @cmnd: a buitin command
 * @f: a pointer to a function that handles the associated builtin command
 */

typedef struct builtin
{
	char *cmnd;
	int (*f)(char **args);
} builtin_t;


/* SHELL */

char **parse_input(char *str);
int check_input(char **args);
char *find_path(char *cmd);
int handle_execs(char **args);
int handle_exit(char **args);
int handle_cd(char **args);
int handle_env(__attribute__((unused)) char **args);
void free_words(char **words);


/* UTILS */
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif /* __SHELL_H__ */
