#include "main.h"

int get_len(char *n);

/**
 * infinite_add - Adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 * Return: pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l1, l2, sum, carry = 0;

	l1 = get_len(n1);
	l2 = get_len(n2);
	if (l1 + 2 > size_r || l2 + 2 > size_r)
		return (0);
	i = l1 - 1;
	j = l2 - 1;
	k = 0;
	while (k < size_r - 1)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		if (i < 0 && j < 0 && sum == 0)
			break;
		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (i >= 0 || j >= 0 || carry)
		return (0);
	r[k] = '\0';
	for (i = 0; i < k / 2; i++)
	{
		char tmp = r[i];
		r[i] = r[k - 1 - i];
		r[k - 1 - i] = tmp;
	}
	return (r);
}

/**
 * get_len - gets length of a string
 * @n: string
 * Return: length
 */
int get_len(char *n)
{
	int len = 0;

	while (n[len])
		len++;
	return (len);
}
