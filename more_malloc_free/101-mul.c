#include "main.h"
#include <stdlib.h>
#include <unistd.h>

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
 * check_args - validates argument count and digit content
 * @argc: argument count
 * @argv: argument vector
 */
void check_args(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();
}

/**
 * multiply - multiplies two number strings and stores result in array
 * @s1: first number string
 * @s2: second number string
 * @result: array to store the result digits
 * @len_result: length of the result array
 */
void multiply(char *s1, char *s2, int *result, int len_result)
{
	int i, j, n1, n2, carry, len1, len2;

	(void)len_result;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = s2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] += carry;
	}
}

/**
 * print_result - prints the result array, skipping leading zeros
 * @result: array containing the result digits
 * @len_result: length of the result array
 */
void print_result(int *result, int len_result)
{
	int i, lead = 0;

	for (i = 0; i < len_result; i++)
	{
		if (result[i])
			lead = 1;
		if (lead || i == len_result - 1)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
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
	int len1, len2, len_result, i, *result;

	check_args(argc, argv);

	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len_result = len1 + len2;

	result = malloc(sizeof(int) * len_result);
	if (!result)
		return (1);

	for (i = 0; i < len_result; i++)
		result[i] = 0;

	multiply(s1, s2, result, len_result);
	print_result(result, len_result);

	free(result);
	return (0);
}
