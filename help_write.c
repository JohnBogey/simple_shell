#include "shell.h"

/**
 * _putsNewLine - prints a line followed by newline to stdout
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
