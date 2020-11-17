#include "shell.h"

char *get_path(char **env)
{
	char **check = env;
	char *path = NULL;
	char  pth[] = "PATH";
	int i, j, stop = 0;
	
	for (i = 0; check[i] && stop == 0; i++)
	{
		for (j = 0; j < 4 && stop == 0; j++)
		{
			if (check[i][j] != pth[j])
				break;
			if (check[i][j] == pth[j] && j == 3)
			{
				path = malloc(_strlen(check[i]));
				_strcpy(path, check[i]);
				stop = 1;
			}
		}
	}	
	return (path);
}

