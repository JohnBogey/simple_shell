#include "shell.h"
#include <string.h>
#include <stdbool.h>

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t size = 0;
	char **cmd;
	int status = 1;

	do
	{
		/*prompt and getline*/
		_puts("$ ");
		line = NULL;
		size = 0;
		if (getline(&line, &size, stdin) == -1)
			status = 0;
		/*set cmd to list of command + other inputs*/
		cmd = _strtok(line, ' ');
		/*run builtin if builtin else run exec_prog*/
		if (exec_builtin(cmd) != 0)
		{
			cmd = cmd_to_arg(cmd);
			status = exec_prog(cmd);
		}
		/*free stuff*/
		free(cmd);
		free(line);
	} while (status)

	return (0);
}
