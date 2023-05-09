#include "main.h"

/**
 * append_text_to_file - appends_text at end_of_file.
 * @filename: points file_name.
 * @text_content: string to add to end_of_file.
 *
 * Return: funct fails or file_name is NULL - -1.
 *         If file does not exist and user lacks write_permissions - -1.
 *         else - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int opn, wrt, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	opn = open(filename, O_WRONLY | O_APPEND);
	wrt = write(opn, text_content, length);
	if (opn == -1 || wrt == -1)
		return (-1);
	close(opn);
	return (1);
}
