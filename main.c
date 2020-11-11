#include "header.h"

int main(int ac, char **av, char **env)
{
	(void)ac, (void)av, (void)env;
	char *line = NULL;
	size_t size = 0;
	char **path = _strtok(getenv("PATH"), ':');
	DIR *directory = NULL;	
	
	_puts("$: ");	
	getline(&line, &size, stdin);
	while (directory != NULL&& *path)
	{
		directory = opendir(*path);
		printf("%s\n", *path);
		
	}
	printf("%d\n", there);
	return (0);
}
