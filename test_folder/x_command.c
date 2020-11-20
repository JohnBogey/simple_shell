#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Uses children to do the hard work.
 * Once they end, the parent continues.
 */

int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/usr/games/cowsay", "-f", "stegosaurus", "hey ;)", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("child is doing labour\n");
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	}
	else
	{
		wait(&status);
		printf("child sacrificed, parent can now go on\n");
	}
	return (0);
}
