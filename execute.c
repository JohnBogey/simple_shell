#include "shell.h"

/**
 * func_exit - ends loop by returning 0
 * @env: evironment variables
 * Return: 0
 */
int func_exit(char **env)
{
	(void)env;
	return (0);
}

/**
 * func_clear - clears screen
 * @env: evironment variables
 * Return: 1
 */
int func_clear(char **env)
{
	char cmd[] = "echo -e \\x1b\\x5b\\x48\\x1b\\x5b\\x32\\x4a\\c";
	char **command;
	(void)env;
	command = _strtok(cmd, " ");
	command = cmd_to_arg(command, env);
	exec_prog(command);
	free2d(command);
	return (1);
}

/**
 * func_env - prints environment
 * @env: evironment variables
 * Return: 1
 */
int func_env(char **env)
{
	char **envStart = env;

	while (*envStart)
	{
		_putsNewLine(*envStart);
		envStart++;
	}
	return (1);
}

/**
 * exec_builtin - matches input to function and runs function
 * @env: list of environment variables
 * @cmds: null terminated string of args for program
 * Return: 1 on success, 0 on exit, -1 on failure
 */

int exec_builtin(char **cmds, char **env)
{
	built_t built_ins[] = {
		{"exit", func_exit},
		{"env", func_env},
		{"clear", func_clear},
		{NULL, NULL}
	};

	int i;

	for (i = 0; built_ins[i].str != NULL; i++)
	{
		if (_strcmp(built_ins[i].str, cmds[0]) == 0)
			return (built_ins[i].func(env));
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
}
