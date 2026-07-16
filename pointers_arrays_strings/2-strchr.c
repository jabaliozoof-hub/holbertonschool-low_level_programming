#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string to be searched
 * @c: the character to be located
 *
 * Return: pointer to the first occurrence of the character c,
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] >= '\0')
	{
		if (s[i] == c)
			return (s + i);
		if (s[i] == '\0')
			break;
		i++;
	}
	return (NULL);
}
