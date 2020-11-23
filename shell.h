#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>

/**
 * struct builtin - Struct builtin
 *
 * @str: command being checked
 * @func: The function associated
 */

typedef struct builtin
{
	char *str;
	int (*func)(char **env);
} built_t;

int _strlen(char *s);
char **_strtok(char *str, char *c);
int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void exec_prog(char **argv);
void free2d(char **lines);
char **cmd_to_arg(char **cmd, char **env);
char *get_path(char **env);
int func_exit(char **env);
int func_env(char **env);
int exec_builtin(char **cmds, char **env);
int _strcmp(char *s1, char *s2);
void _putsNewLine(char *str);
#endif /*HEADER_H*/
