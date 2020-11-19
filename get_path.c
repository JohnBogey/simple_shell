#include "shell.h"

/**
 * get_path - gets path variable from environment
 * Return: string value of PATH
 * @env: environment array from main
 */

char *get_path(char **env)
{
	char **check = env;
	char *path = NULL;
	char  pth[] = "PATH";
	char *current;
	char *p;
	int i, j, stop = 0;

	for (i = 0; check[i] && stop == 0; i++)
	{
		for (j = 0; j < 4 && stop == 0; j++)
		{
			if (check[i][j] != pth[j])
				break;
			if (check[i][j] == pth[j] && j == 3)
			{
				path = malloc(strlen(check[i]) + 1);
				if (path == NULL)
					return (NULL);
				strcpy(path, check[i]);
				stop = 1;
			}
		}
	}
	current = path;
	while (*current != '/')
		current++;
	p = malloc(strlen(path) + 1 - 4);
	strcpy(p, current);
	free(path);
	return (p);
}

