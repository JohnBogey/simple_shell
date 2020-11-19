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

int _strlen(char *s);
char **_strtok(char *str, char c);
int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void exec_prog(char **argv);
void free2d(char **lines);
char **cmd_to_arg(char **cmds);
char *get_path(char **env);
int func_exit(void);
#endif /*HEADER_H*/
