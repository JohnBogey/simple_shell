#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct builtin - Struct builtin
 *
 * @cmd: command being checked
 * @f: The function associated
 */
typedef struct builtin
{
	char *cmd;
	char *(*func)(char **argv);
} built_t;

/**
 * exec_builtin - matches input to function and runs function
 * @argv: null terminated string of args for program
 * Return: 0 on success, -1 on failure
 */
int exec_builtin(char **argv)
{
	built_t function[] = {
		{"exit", func_exit},
		{"cd", func_cd},
		{NULL, NULL}
	};

	int i = 0;

	for (i = 0; *(function + i)->cmd, i++)
		if (*(function + i)->cmd == argv[0])
		{
			function = *(function + i)->func;
			function(argv);
			return (0);
		}
	return (-1);
}

/**
 * exec_prog - uses children to execve program
 * @argv: null terminated string of args for program
 * Return: always 0
 */

void exec_prog(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{	
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	}
	else
		wait(&status);
	return;
}
