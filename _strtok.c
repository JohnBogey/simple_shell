#include "shell.h"

/**
 * _strtok - takes a stirng snd splits it up into words
 * @str: string passed from main
 * @c: delimiter of string
 * Return: a pointer to array of strings or NULL
 */

char **_strtok(char *str, char c)
{
	int i, j, word_count = 0, word_length, word_index = 0, copy_index, temp;
	char **word_list;

	if (str == NULL || _strlen(str) == 0)
		return (NULL);
	for (i = 0; str[i]; i++)
		if (str[i + 1] == c)
			word_count++;
	if (str[i - 1] != c)
		word_count++;
	word_list = (char **)malloc(word_count * sizeof(char *) + 1);
	if (word_list == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		if ((str[i] == c || i == 0) && str[i + 1] != c && str[i + 1] != '\0')
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				continue;
			if (str[i] == c)
				i++;
			word_length = 1;
			temp = i;
			copy_index = 0;
			for (j = i; str[j] != c && str[j]; j++)
				word_length++;
			word_list[word_index] = (char *)malloc(word_length);
			if (word_list[word_index] == NULL)
			{
				for (; word_index > 0; word_index--)
					free(word_list[word_index]);
				free(word_list);
				return (NULL);
			}
			word_list[word_index][word_length] = '\0';
			for (; temp < j; temp++, copy_index++)
				word_list[word_index][copy_index] = str[temp];
			word_index++;
		}
	word_index++;
	word_list[word_index] = '\0';
	return (word_list);
}
