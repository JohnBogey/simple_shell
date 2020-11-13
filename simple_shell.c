#include "shell.h"
#include <string.h>
#include <stdbool.h>
#include <signal.h>

/**
 * main - a very simple shell
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t size = 0;
	char **cmd;
	int status;

	signal(SIGINT, SIG_IGN);
	do {
		/*prompt and getline*/
		_puts("$ ");
		line = NULL;
		size = 0;
		if (getline(&line, &size, stdin) == -1)
		{
			free2d(cmd);
			free(line);
			status = 0;
			continue;
		}
		/*set cmd to list of command + other inputs*/
		cmd = _strtok(line, ' ');
		/*run builtin if builtin else run exec_prog*/
		status = exec_builtin(cmd);
		if (status == -1)
		{
			cmd = cmd_to_arg(cmd);
			exec_prog(cmd);
			status = 1;
		}
		/*free stuff*/
		free2d(cmd);
		free(line);
	} while (status)
	return (0);
}
