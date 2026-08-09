#include "main.h"
#include <stdio.h>

void close_error(int fd);

/**
 * close_error - Helper function to close file descriptors and handle errors.
 * @fd: The file descriptor to close.
 */
void close_error(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t nrd, nwr;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_error(fd_from);
		exit(99);
	}
	while ((nrd = read(fd_from, buf, 1024)) > 0)
	{
		nwr = write(fd_to, buf, nrd);
		if (nwr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_error(fd_from);
			close_error(fd_to);
			exit(99);
		}
	}
	if (nrd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_error(fd_from);
		close_error(fd_to);
		exit(98);
	}
	close_error(fd_from);
	close_error(fd_to);
	return (0);
}

