#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
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
