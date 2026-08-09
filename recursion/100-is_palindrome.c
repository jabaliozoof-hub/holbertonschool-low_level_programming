#include "main.h"

/**
 * _get_strlen - Returns the length of a string recursively.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int _get_strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _get_strlen(s + 1));
}

/**
 * check_palindrome - Helper function to recursively check palindrome characters.
 * @s: The string.
 * @start: Start index.
 * @end: End index.
 *
 * Return: 1 if palindrome, 0 if not.
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if it is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
	{
		return (1);
	}
	len = _get_strlen(s);
	return (check_palindrome(s, 0, len - 1));
}

