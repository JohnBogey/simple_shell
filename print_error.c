#include "shell.h"

/**
 * _itoa - converts int to string
 * @value: the int to convert
 * Return: formatted string
 */
char *_itoa(int value)
{
	char string[10], *final_string;
	int size = 1, pos = 0, copy = value, mul = 1;

	while (copy > 10)
	{
		copy /= 10;
		mul *= 10;
		size += 1;
	}
	while (size > 0)
	{
		if ((value / mul) < 10)
			string[pos] = (value / mul) + '0';
		else
			string[pos] = ((value / mul) % 10) + '0';
		size--;
		pos++;
		mul /= 10;
	}
	string[pos] = '\0';
	final_string = malloc(_strlen(string) + 1);
	_strcpy(final_string, string);
	return (final_string);
}

/**
 * print_error - prints formatted error message
 * @av: list of arguments
 * @cmd: list of commands
 * @count: current input line
 * Return: nothing
 */
void print_error(char *av, int count, char *cmd)
{
	char delim[3] = ": ", nf[10] = "not found\n";
	char *number = _itoa(count), *buffer = malloc(3072 * sizeof(char));

	_strcpy(buffer, av);
	_strcat(buffer, delim);
	_strcat(buffer, number);
	free(number);
	_strcat(buffer, delim);
	_strcat(buffer, cmd);
	_strcat(buffer, delim);
	_strcat(buffer, nf);
	_puts(buffer);
	free(buffer);
}
