#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void close_f(int file_d);
char *create_bufff(char *f);

/**
 * close_f - close_file_descriptors.
 * @file_d: file_descriptor to close.
 */
void close_f(int file_d)
{
	int cls;

	cls = close(file_d);
	if (cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_d);
		exit(100);
	}
}
/**
 * create_bufff - allocates_1024_bytes for buff.
 * @f: name of file_uffer storing chars.
 *
 * Return: pointer to newly_allocated buff.
 */
char *create_bufff(char *f)
{
	char *bufff;

	bufff = malloc(sizeof(char) * 1024);
	if (bufff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f);
		exit(99);
	}
	return (bufff);
}
/**
 * main - copies contents of file to another f.
 * @argc: num of arguments_supplied to program.
 * @argv: array of pointers to arguments.
 *
 * Return: 0 success.
 *
 * Description: If argument_count incorrect - exit_code 97.
 * If f_from not_exist or not_read - exit_code 98.
 * If f_to not_created or not_written to - exit_code 99.
 * If file_to or file_from not_closed - exit_code 100.
 */
int main(int argc, char *argv[])
{
	int wrt, rd, from_, to_;
	char *bufff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bufff = create_bufff(argv[2]);
	from_ = open(argv[1], O_RDONLY);
	rd = read(from_, bufff, 1024);
	to_ = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from_ == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(bufff);
			exit(98);
		}
		wrt = write(to_, bufff, rd);
		if (to_ == -1 || wrt == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(bufff);
			exit(99);
		}
		rd = read(from_, bufff, 1024);
		to_ = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(bufff);
	close_f(from_);
	close_f(to_);
	return (0);
}
