#include "main.h"

/**
 * flip_bits - counts num of bits to change
 * to get frm one num to anothr
 * @n: first num
 * @m: second num
 *
 * Return: num of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, cnt = 0;
	unsigned long int exclusiv = n ^ m;
	unsigned long int curr;

	for (k = 63; k >= 0; k--)
	{
		curr = exclusiv >> k;
		if (curr & 1)
			cnt++;
	}

	return (cnt);
}
