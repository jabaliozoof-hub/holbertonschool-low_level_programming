#include "main.h"
#include <stdlib.h>

/**
 * _strlen - computes the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to the newly allocated space, or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (n >= len2)
		n = len2;

	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
	{
		concat[i] = s1[i];
	}

	for (j = 0; j < n; j++)
	{
		concat[i + j] = s2[j];
	}

	concat[i + j] = '\0';

	return (concat);
}
