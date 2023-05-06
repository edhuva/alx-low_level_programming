#include "main.h"

/**
 * get_endianness - checks if machine is little_ or big_ endian
 * Return: 0 big_, 1 little_
 */
int get_endianness(void)
{
	unsigned int k = 1;
	char *c = (char *) &k;

	return (*c);
}
