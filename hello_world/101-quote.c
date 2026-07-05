#include <unistd.h>

/**
 * main - Prints exactly a specific quote to standard error.
 *
 * Return: 1 (Success as per instructions)
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
