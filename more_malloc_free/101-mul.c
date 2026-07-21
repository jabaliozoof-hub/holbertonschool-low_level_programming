#include "main.h"
#include <stdlib.h>
#include <unistd.h>

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
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * print_error - prints Error and exits with 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to evaluate
 *
 * Return: 0 if non-digit found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len_result, i, j, n1, n2, carry, *result, lead = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();
	s1 = argv[1], s2 = argv[2];
	len1 = _strlen(s1), len2 = _strlen(s2);
	len_result = len1 + len2;
	result = malloc(sizeof(int) * len_result);
	if (!result)
		return (1);
	for (i = 0; i < len_result; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		n1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1, j = len2; j >= 0; j--)
		{
			n2 = s2[j] - '0';
			carry += result[len1 + j + 1] + (n1 * n2);
			result[len1 + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry)
			result[len1 + j + 1] += carry;
	}
	for (i = 0; i < len_result; i++)
	{
		if (result[i])
			lead = 1;
		if (lead || i == len_result - 1)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
