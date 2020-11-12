#include "shell.h"
#include <string.h>
#include <stdbool.h>

int main(int ac, char **av, char **env)
{
	(void)ac, (void)av, (void)env;
	char *line = NULL;
	size_t size = 0;
	char **path = _strtok(getenv("PATH"), ':');
	char *pth;
	int status = -1;
	
	_puts("$: ");	
	getline(&line, &size, stdin);
	line[strlen(line) - 1] = '\0';
	while (*path && status == -1)
	{
		*path = _strcat(*path, "/");
		*path = _strcat(*path,line);
		pth = strdup(*path);
		status = access(pth, F_OK | X_OK);
		path++;
	}
	printf("%s\n", pth);	
	return (0);
}
