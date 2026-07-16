#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - prints a buffer
 * @b: pointer to the buffer
 * @size: size of the buffer
 *
 * Return: nothing
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x:", i);
		for (j = i; j < i + 10; j++)
		{
			if (j % 2 == 0)
				printf(" ");
			if (j < size)
				printf("%02x", (unsigned char)b[j]);
			else
				printf("  ");
		}
		printf(" ");
		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				if (isprint(b[j]))
					printf("%c", b[j]);
				else
					printf(".");
			}
		}
		printf("\n");
	}
}
