#include "shell.h"
#include <string.h>
#include <stdbool.h>

int main(int ac, char **av, char **env)
{
	(void)ac, (void)av, (void)env;
	char *line = NULL;
	size_t size = 0;
	char **path = _strtok(getenv("PATH"), ':');
	char **pathStart = path;
	char **cmd;
	int status = -1;
	//int i;
	
	_puts("$: ");	
	getline(&line, &size, stdin);
	line[_strlen(line) - 1] = '\0';
	cmd = _strtok(line, ' ');
	while (*path)
	{
		*path = _strcat(*path, "/");
		*path = _strcat(*path,line);
		status = access(*path, F_OK | X_OK);
		if (status == 0)
			break;
		//printf("%s::%d::", *path, status);
		path++;
	}	
	free(line);
	cmd[0] = *path;
	av = cmd;
	exec_prog(av);	
	free2d(pathStart);
	
	return (0);
}
