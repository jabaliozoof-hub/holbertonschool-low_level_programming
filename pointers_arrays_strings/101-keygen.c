#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a valid password for 101-crackme
 * Return: 0 on success
 */
int main(void)
{
	int i, sum = 0;
	char password[100];
	int target = 2772;

	srand(time(NULL));

	for (i = 0; sum < target - 127; i++)
	{
		password[i] = (rand() % 94) + 33;
		sum += password[i];
	}

	password[i] = target - sum;
	password[i + 1] = '\0';

	printf("%s", password);

	return (0);
}
