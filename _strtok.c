#include "shell.h"

/**
 * _strtok - takes a strings and formats as an array
 * of strings using strtok
 * Return: array of tokenized strings
 * @str: string to be parsed
 * @delim: pointer to single char that separates
 * needed strings from str
 */

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

