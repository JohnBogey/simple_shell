#include "shell.h"
#include <string.h>
#include <stdbool.h>
#include <signal.h>

/**
 * kill_block - stops ctrl+c
 * Return: always nothing
 */
void kill_block(int sig)
{
	(void)signal;
	_puts("\n$ ");
}

/**
 * main - a very simple shell
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t size = 0;
	char **cmd;
	int status = 1;

	signal(SIGINT, kill_block);
	do {
		if (isatty(STDIN_FILENO) != 0)
			_puts("$ ");
		line = NULL;
		size = 0;
		if (getline(&line, &size, stdin) == -1)
		{
			_putchar('\n');
			free(line);
			status = 0;
			continue;
		}
		if (line[0] != '\n')
			stuff;
		free(line);
	} while (status);
	return (0);
}
