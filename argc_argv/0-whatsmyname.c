#include "main.h"
#include <stdio.h>

/**
 * main - prints its name, followed by a new line
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the strings
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
