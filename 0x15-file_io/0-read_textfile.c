#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- reads text_file and  prints to the STDOUT.
 * @filename: text_fie
 * @letters: num of letters_to_read
 *
 * Return: w- actual num of bytes_read and print
 *        0 func fails or filename NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bufff;
	ssize_t file_d;
	ssize_t t_;
	ssize_t wrt;

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	bufff = malloc(sizeof(char) * letters);
	t_ = read(file_d, bufff, letters);
	wrt = write(STDOUT_FILENO, bufff, t_);

	free(bufff);
	close(file_dd);
	return (wrt);
}
