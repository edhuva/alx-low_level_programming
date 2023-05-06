#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes char to stdout
 * @c: char to print
 *
 * Return: On success 1.
 * On err, -1 is returned, err is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
