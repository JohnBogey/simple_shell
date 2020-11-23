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
	return;
}

void freeall(char **cmd, char **check)
{
	free2d(cmd);
	free2d(check);
	return;
}
