#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long i;

	while (n % 2 == 0)
	{
		n /= 2;
	}

	for (i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
		}
	}

	printf("%lu\n", n);

	return (0);
}
