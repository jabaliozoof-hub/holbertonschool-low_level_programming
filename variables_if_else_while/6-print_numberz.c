#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0
 * using only putchar and integer variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		/* 48 is the ASCII value for '0' */
		putchar(n + '0');
	}
	putchar('\n');

	return (0);
}
