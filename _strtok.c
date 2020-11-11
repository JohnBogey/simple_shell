#include "header.h"

/**
* _strtok - takes a stirng snd splits it up into words
* @str: string passed from main
* Return: a pointer to array of strings or NULL
*/

char **_strtok(char *str, char c)
{
	int i, j, numOfWords = 0, charLength, wIdx = 0, cpyIdx, i2;
	char **words;

	if (str == NULL || _strlen(str) == 0)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i + 1] == c)
			numOfWords++;
	}
	i--;
	if (str[i] != c)
		numOfWords++;
	words = (char **)malloc(numOfWords * sizeof(char *) + 1);
	if (words == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if ((str[i] == c || i == 0) && str[i + 1] != c && str[i + 1] != '\0')
		{
			if (str[i] == c)
				i++;
			charLength = 1;
			i2 = i;
			cpyIdx = 0;
			for (j = i; str[j] != c && str[j]; j++)
				charLength++;
			words[wIdx] = (char *)malloc(charLength);
			if (words[wIdx] == NULL)
			{
				for (; wIdx > 0; wIdx--)
					free(words[wIdx]);
				free(words);
				return (NULL);
			}
			words[wIdx][charLength] = '\0';
			for (; i2 < j; i2++, cpyIdx++)
				words[wIdx][cpyIdx] = str[i2];
			wIdx++;
		}
	}
	wIdx++;
	words[wIdx] = '\0';
	return (words);
}

