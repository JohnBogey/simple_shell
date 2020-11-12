#include "shell.h"

/**
 * exec_built - executes built in function
 *
 *
 */

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
		return;;
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
