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
	char *str;
	int (*func)(void);
} built_t;

/**
 * exec_builtin - matches input to function and runs function
 * @argv: null terminated string of args for program
 * Return: 1 on success, 0 on exit, -1 on failure
 */

int exec_builtin(char **commands)
{
	built_t built_ins[] = {
		{"exit", func_exit},
		{NULL, NULL}
	};

	int i = 0, function;

	for (i = 0; built_ins[i].str != NULL; i++)
		if (_strcmp(built_ins[i].str, commands[0]) == 0)
		{
			return (built_ins[i].func());
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
		execve(argv[0], argv, NULL);
		perror("Error:");
		_exit(0);
	}
	else
		wait(&status);
	return;
}
