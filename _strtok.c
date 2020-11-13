#include "shell.h"

char **_strtok(char *str, char delim)
{	
	char **doubl;
	char *s = str;
	int i = 1;	
	
	while (*s)
	{
		if (*s == delim)
			i++;
		s++;
	}
	doubl = malloc(sizeof(char *) * i);
	i = 0;
	s = strtok(str, &delim);
	while (1)
	{	
		if (s == NULL)
			break;
		doubl[i] = malloc(sizeof(char) * _strlen(s) + 1);
		doubl[i] = _strcpy(doubl[i], s);
		i++;
		s = strtok(NULL, &delim);
	}
	return (doubl);
}
