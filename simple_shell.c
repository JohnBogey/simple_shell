#include "shell.h"
#include <string.h>
#include <stdbool.h>
#include <signal.h>

extern int errno;
/**
 * kill_block - stops ctrl+c
 * Return: always nothing
 */
void kill_block(int sig)
{
	(void)sig;
	_puts("\n$ ");
}

/**
 * main - a very simple shell
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
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
		if (line[0] != '\n' && line[0] != ' ')
		{
			/*set last newline to nullbyte*/
			line[_strlen(line) - 1] = '\0';
			/*set cmd to array of commands/flags*/
			cmd = _strtok(line, " ");
			/*check built ins, run if found*/
<<<<<<< HEAD
			status = exec_builtin(cmd, env);
			if (status == -1)
			{
				/*turns cmc to args for exec*/
				cmd = cmd_to_arg(cmd, env);
				/*execute program if found*/
				if (cmd != NULL)
					exec_prog(cmd);	
			}
			if (cmd != NULL)
				free2d(cmd);
		}	
=======
			status = exec_builtin(cmd);
			if (status == -1)
			{
				/*turns cmd to args for exec*/
				cmd = cmd_to_arg(cmd, env);
				/*execute program if found*/
				exec_prog(cmd);
				status = 1;
			}
			/*free stuff*/
			free2d(cmd);
		}
>>>>>>> 84f1f992a5add9efff9bb7695e504f10f3f2bfc6
		free(line);
	}
	return (0);
}
