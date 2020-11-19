#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

char **_strtok(char *str, char *delim)
{
        char **doubl;
        char *s = str;
        char *string;
        int i = 0;

        while (*s)
        {
                if (*s == *delim)
                        i++;
                s++;
        }
        doubl = malloc(sizeof(char *) * (i + 2));
        if (doubl == NULL)
		return (NULL);
	i = 0;
        string = strtok(str, delim);
        while (1)
        {
                if (string == NULL)
                  break;
                doubl[i] = malloc(sizeof(char) * strlen(string) + 1);
                if (doubl[i] == NULL)
		{
			free2d(doubl);
			return (NULL);
		}
		strcpy(doubl[i], string);
                i++;
                string = strtok(NULL, delim);
        }
	doubl[i] = NULL;
	return (doubl);
}

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

char **cmd_to_arg(char **cmd, char **env)
{

        /* FREE PATH BEFORE END */
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
	if(check[i] == NULL)
	{	
		free2d(cmd);
		return (NULL);
	}
	for (j = 0; cmd[j] != NULL; j++);
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

int main(int ac, char **av, char **env)
{
        (void)ac, (void)av, (void)env;
        char line[] = "ls -la -R";
        //size_t size = 0;
        char **cmd; //**cmdStart;
        int i = 0; //j = 0;

        cmd = _strtok(line, " ");
        cmd = cmd_to_arg(cmd, env);
	while (cmd[i] != NULL)
	{
		puts(cmd[i]);
		i++;
	}
	free2d(cmd);
	return (0);
}
