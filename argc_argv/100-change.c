#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int values[] = {25, 10, 5, 2, 1};
	int i, size;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	size = sizeof(values) / sizeof(values[0]);

	for (i = 0; i < size; i++)
	{
		if (cents >= values[i])
		{
			coins += cents / values[i];
			cents %= values[i];
		}
	}

	printf("%d\n", coins);

	return (0);
}
