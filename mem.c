#include "shell.h"

void free1d(char *line)
{
	free(line);
	return;
}

void free2d(char **lines)
{
	char **current = lines;
	char *line;
	int i = 0;
	while (*current)
	{
		i++;
		current++;
	}
	for (; i > 0; i--)
	{
		line = lines[i];
		free(line);
	}	
	return;
}
