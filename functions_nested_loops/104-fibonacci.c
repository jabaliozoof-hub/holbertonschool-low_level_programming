#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long a1 = 0, a2 = 1, b1 = 0, b2 = 2;
	unsigned long next1, next2, carry;
	int i;

	printf("%lu, %lu", a2, b2);
	for (i = 3; i <= 98; i++)
	{
		carry = (a2 + b2) / 1000000000000000000;
		next2 = (a2 + b2) % 1000000000000000000;
		next1 = a1 + b1 + carry;
		printf(", %lu%018lu", next1, next2);
		a1 = b1;
		a2 = b2;
		b1 = next1;
		b2 = next2;
	}
	printf("\n");
	return (0);
}
