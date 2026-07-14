#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char tmp;

	while (s[len] != '\0')
	{
		len++;
	}

	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
}
