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
	char slash[] = "/";
	char **args = NULL, **pths = _strtok(path, ":"), **check;
	int status = -1, i = 0, j;

	free(path);
	for (i = 0; pths[i] != NULL; i++)
		;
	check = malloc(sizeof(char *) * (i + 1));
	if (check == NULL)
	{
		free2d(cmd);
		return (NULL);
	}
	for (i = 0; pths[i] != NULL; i++)
	{
		check[i] = malloc(strlen(pths[i]) + strlen(cmd[0]) + 2);
		if (check[i] == NULL)
		{
			free2d(check);
			free2d(pths);
			free2d(cmd);
			return (NULL);
		}
		strcpy(check[i], pths[i]);
		strcat(check[i], slash);
		strcat(check[i], cmd[0]);
	}
	check[i] = NULL;
	free2d(pths);
	for (i = 0; check[i] != NULL; i++)
	{
		status = access(check[i], F_OK | X_OK);
		if (status == 0)
			break;
	}
	if (check[i] == NULL)
	{
		free2d(cmd);
		return (NULL);
	}
	for (j = 0; cmd[j] != NULL; j++)
		;
	args = malloc(sizeof(char *) * (j + 1));
	if (args == NULL)
	{
		free2d(check);
		free2d(cmd);
		return (NULL);
	}
	args[0] = malloc(strlen(check[i]) + 1);
	strcpy(args[0], check[i]);
	free2d(check);
	for (i = 1; cmd[i] != NULL; i++)
	{
		args[i] = malloc(strlen(cmd[i] + 1));
		if (args[i] == NULL)
		{
			free2d(args);
			free2d(cmd);
		}
		strcpy(args[i], cmd[i]);
	}
	args[i] = NULL;
	free2d(cmd);
	return (args);
}

