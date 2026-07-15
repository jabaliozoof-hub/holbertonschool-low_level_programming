#include "main.h"

/**
 * leet - encodes a string into 1337.
 * @s: pointer to the string.
 *
 * Return: pointer to the encoded string.
 */
char *leet(char *s)
{
	int i, j;
	char l[] = "aAeEoOtTlL";
	char n[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; l[j] != '\0'; j++)
		{
			if (s[i] == l[j])
			{
				s[i] = n[j];
			}
		}
	}
	return (s);
}
