#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 *                 it to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: Number of letters to read and print.
 *
 * Return: Actual number of letters read and printed, or 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}
	nrd = read(fd, buf, letters);
	if (nrd == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	nwr = write(STDOUT_FILENO, buf, nrd);
	free(buf);
	close(fd);
	if (nwr == -1 || nwr != nrd)
		return (0);
	return (nwr);
}
