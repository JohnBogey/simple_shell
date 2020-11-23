#include "shell.h"
#include <string.h>
#include <stdbool.h>
#include <signal.h>


/**
 * kill_block - stops ctrl+c
 * @sig: signal
 * Return: always nothing
 */
void kill_block(int sig)
{
	(void)sig;
	_puts("\n$ ");
}

/**
 * main - a very simple shell
 * @ac: number of arguments
 * @av: list of arguments
 * @env: list of environment variables
 * Return: always 0
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line = NULL, *command, **cmd;
	size_t size = 0;
	int status = 1, line_count = 0;

	signal(SIGINT, kill_block);
	while (status)
	{
		if (isatty(STDIN_FILENO) == 1)
			_puts("$ ");
		line = NULL;
		size = 0;
		line_count += 1;
		if (getline(&line, &size, stdin) == -1)
		{
			_putchar('\n');
			free(line);
			status = 0;
			continue;
		}
		if (line[0] != '\n' && line[0] != ':')
		{
			line[_strlen(line) - 1] = '\0';
			cmd = _strtok(line, " ");
			status = exec_builtin(cmd, env);
			if (status == -1)
			{
				if (access(cmd[0], F_OK) != 0)
				{
					command = malloc(_strlen(cmd[0]));
					_strcpy(command, cmd[0]);
					cmd = cmd_to_arg(cmd, env);
				}
				if (cmd != NULL)
					exec_prog(cmd);
				else
					print_error(av[0], line_count, command);
				free(command);
				status = 1;
			}
			if (cmd != NULL)
				free2d(cmd);
		}
		free(line);
	}
	return (0);
}
