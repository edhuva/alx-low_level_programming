#include "main.h"

/**
 * get_bit - returns val of a bit at indx in a decimal_num
 * @n: num to search
 * @index: indx of  bit
 *
 * Return: val of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);
	bit_value = (n >> index) & 1;
	return (bit_value);
}
