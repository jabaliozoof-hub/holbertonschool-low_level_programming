#include "main.h"

/**
 * _helper_prime - Recursively checks if a number is divisible.
 * @n: The number to check.
 * @i: The current divisor.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int _helper_prime(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (_helper_prime(n, i + 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is a prime number,
 *                   otherwise returns 0.
 * @n: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (_helper_prime(n, 2));
}

