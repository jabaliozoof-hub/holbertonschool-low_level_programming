#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src.
 * @dest: the destination string.
 * @src: the source string.
 * @n: maximum number of bytes to use from src.
 *
 * Return: pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len;
	int i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';

	return (dest);
}
