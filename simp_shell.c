#include "shell.h"
#include <string.h>
#include <stdbool.h>

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t size = 0;
	char **path = _strtok(getenv("PATH"), ':'), **pathStart = path, **cmd;
	int status = 1;

	while (status)
	{
		/*prompt and getline*/
		_puts("$ ");
		if (getline(&line, &size, stdin) == -1)
		{
			status = 0;
			continue;
		}
		/*set cmd to list of command + other inputs*/
		cmd = str_tokens(line, ' ');
		/*check if newline*/
		if (cmd[0] == '\n')
		{
			free(line);
			free2d(cmd);
			continue;
		}
		/*run builtin if builtin else run exec_prog*/
		if (exec_builtin(cmd) != 0)
			exec_prog(cmd);
	}
	free2d(path_start);
	free2d(cmd);
	return (0);
}
