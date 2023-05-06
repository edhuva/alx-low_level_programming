#include "main.h"

/**
 * set_bit - setting a bit at given indx to 1
 * @n: points num to change
 * @index: indx of bit to set to 1
 *
 * Return: 1 success, -1  failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
