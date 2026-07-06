#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2.
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	unsigned long a = 1, b = 2, next;

	printf("%lu, %lu", a, b);

	for (count = 2; count < 50; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	printf("\n");
	return (0);
}
