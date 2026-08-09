#include "main.h"

/**
 * _helper_sqrt - Finds the natural square root recursively.
 * @n: The number.
 * @i: The iterator/guess.
 *
 * Return: The square root, or -1 if it doesn't have one.
 */
int _helper_sqrt(int n, int i)
{
	if ((i * i) > n)
	{
		return (-1);
	}
	if ((i * i) == n)
	{
		return (i);
	}
	return (_helper_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number.
 *
 * Return: The natural square root, or -1 if none.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_helper_sqrt(n, 0));
}

