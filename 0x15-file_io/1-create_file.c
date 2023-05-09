#include "main.h"

/**
 * create_file - creates_file.
 * @filename: points file_name to create.
 * @text_content: points string_to_write to file.
 *
 * Return: func fails - -1.
 *         else - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_d, wrt, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	file_d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrt = write(file_d, text_content, length);
	if (file_d == -1 || wrt == -1)
		return (-1);
	close(file_d);
	return (1);
}
