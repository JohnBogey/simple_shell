#include "shell.h"


/**
 * _puts - prints a line to stdout
 * Return: void
 * @str: string passed to function from main
 */

void _putsNewLine(char *str)
{
        char *print = str;

        while (*print)
        {
                _putchar(*print);
                print++;
        }
	_putchar('\n');
}



/**
 * _puts - prints a line to stdout
 * Return: void
 * @str: string passed to function from main
 */

void _puts(char *str)
{
	char *print = str;

	while (*print)
	{
		_putchar(*print);
		print++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcpy - copys a string
 * Return: pointer to copy
 * @dest: destination of copy
 * @src: original string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of string s
 * Return: length
 * @s: string passed from main
 */

int _strlen(char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; length++)
		;
	return (length);
}

/**
 * _strcat - concatenates two strings
 * Return: dest;
 * @src: src of first string
 * @dest: where both concat strings will end up
 */

char *_strcat(char *dest, char *src)
{
	int destLength, i;

	for (destLength = 0; dest[destLength]; destLength++)
		;
	for (i = 0; i < destLength + 1 && src[i] != '\0'; i++)
	{
		dest[destLength + i] = src[i];
	}
	dest[destLength + i] = '\0';
	return (dest);

}

/**
 * _strcmp - compares two strings
 * @s1: string
 * @s2: string
 *
 * Return: dest
 */

int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}
