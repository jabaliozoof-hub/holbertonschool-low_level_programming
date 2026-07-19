#include "main.h"
#include <stdlib.h>

/**
 * word_len - helper to find word length
 * @str: string
 * Return: length of word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

/**
 * count_words - helper to count words
 * @str: string
 * Return: number of words
 */
int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
	char **tab, *word;
	int i, j, k, wc, wl;

	if (str == NULL || *str == '\0')
		return (NULL);
	wc = count_words(str);
	if (wc == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (wc + 1));
	if (tab == NULL)
		return (NULL);
	for (i = 0, k = 0; k < wc; k++)
	{
		while (str[i] == ' ')
			i++;
		wl = word_len(&str[i]);
		word = malloc(sizeof(char) * (wl + 1));
		if (word == NULL)
		{
			for (j = 0; j < k; j++)
				free(tab[j]);
			free(tab);
			return (NULL);
		}
		for (j = 0; j < wl; j++)
			word[j] = str[i++];
		word[j] = '\0';
		tab[k] = word;
	}
	tab[k] = NULL;
	return (tab);
}
