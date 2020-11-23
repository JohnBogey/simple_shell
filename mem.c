#include "shell.h"

/**
 * free2d - frees 2d array
 * @lines: 2d array
 * Return: nothing
 */
void free2d(char **lines)
{
	int i = 0;

	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

/**
 * freeall - frees 2 arrays of strings
 * @cmd: array of strings
 * @check: array of string
 * Return: void
 */

void freeall(char **cmd, char **check)
{
	free2d(check);
	free2d(cmd);
}
