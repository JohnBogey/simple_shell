#include "shell.h"

/**
 * cmd_to_arg - function that take commands, checks all
 * paths in PATH, and returns array of strings with
 * full path and flags
 * Return: array of strings, full path and flags if
 * it exists, else NULL
 * @cmd: array of strings from main
 * @env: environment variable from main
 */

char **cmd_to_arg(char **cmd, char **env)
{
	char *path = get_path(env);
	char **args = NULL, **pths = _strtok(path, ":"), **check;
	int i = 0, j;

	free(path);
	for (i = 0; pths[i] != NULL; i++)
		;
	check = malloc(sizeof(char *) * (i + 1));
	if (check == NULL)
	{
		free2d(cmd);
		return (NULL);
	}
	j = populate(check, pths, cmd);
	if (j == 0)
	{
		freeall(check, cmd);
		return (NULL);
	}
	i = checkpath(check);
	if (i == 0)
	{
		freeall(check, cmd);
		return (NULL);
	}
	for (j = 0; cmd[j] != NULL; j++)
		;
	args = malloc(sizeof(char *) * (j + 1));
	if (args == NULL)
	{
		freeall(check, cmd);
		return (NULL);
	}
	j = populateargs(args, check, cmd, i);
	if (j == 0)
	{
		free(check);
		return (NULL);
	}
	freeall(check, cmd);
	return (args);
}

/**
 * populateargs - populates args array with path
 * name of executable file and options after the command
 * @args: array to be populated with full path and command flags
 * @check: array of full path names checked
 * @cmd: array of commands from user
 * @i: index of correct path in check array
 * Return: 1 on success else 0
 */

int populateargs(char **args, char **check, char **cmd, int i)
{
	args[0] = malloc(_strlen(check[i]) + 1);
	_strcpy(args[0], check[i]);
	for (i = 1; cmd[i] != NULL; i++)
	{
		args[i] = malloc(_strlen(cmd[i]) + 1);
		if (args[i] == NULL)
		{
			freeall(args, cmd);
			return (0);
		}
		_strcpy(args[i], cmd[i]);
	}
	args[i] = NULL;
	return (1);
}

/**
 * populate - takes parsed path and adds a
 * slash and the first string in the cmd array
 * @check: array of strings to be populated
 * @pths: array of strings that is parsed $PATH
 * @cmd: input from user
 * Return: 1 on success else 0
 */

int populate(char **check, char **pths, char **cmd)
{
	int i;
	char slash[] = "/";

	for (i = 0; pths[i] != NULL; i++)
	{
		check[i] = malloc(_strlen(pths[i]) + _strlen(cmd[0]) + 2);
		if (check[i] == NULL)
		{
			freeall(check, cmd);
			free2d(pths);
			return (0);
		}
		_strcpy(check[i], pths[i]);
		_strcat(check[i], slash);
		_strcat(check[i], cmd[0]);
	}
	check[i] = NULL;
	free2d(pths);
	return (1);
}

/**
 * checkpath - checks the path to file and sees if it is
 * there and able to be executed
 * @check: array of the paths
 * Return: index of the valid path in the check array or 0 if none found
 */
int checkpath(char **check)
{
	int status = -1, i = 0;

	for (i = 0; check[i] != NULL; i++)
	{
		status = access(check[i], F_OK | X_OK);
		if (status == 0)
			break;
	}
	if (check[i] == NULL)
		return (0);
	return (i);
}
