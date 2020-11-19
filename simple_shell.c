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
	while (status)
	{
		/*prompt if stdin*/
		if (isatty(STDIN_FILENO) == 1)
			_puts("$ ");
		/*reset variables for getline*/
		line = NULL;
		size = 0;
		/*get the line, on EOF or failure exit*/
		if (getline(&line, &size, stdin) == -1)
		{
			_putchar('\n');
			free(line);
			status = 0;
			continue;
		}
		if (line[0] != '\n')
		{
			/*set cmd to array of commands/flags*/
			cmd = _strtok(line, ' ');
			cmd[0][_strlen(cmd[0]) - 1] = '\0';
			/*check built ins, run if found*/
			status = exec_builtin(cmd);
			if (status == -1)
			{
				/*execute program if found*/
				exec_prog(cmd);
				status = 1;
			}
			/*free stuff*/
			free2d(cmd);
		}
		free(line);
	}
	return (0);
}
