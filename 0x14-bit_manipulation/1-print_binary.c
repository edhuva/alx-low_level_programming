#include "main.h"

/**
 * print_binary - printing binary equivalnt of a decimal_num
 * @n: num printed in binary
 */
void print_binary(unsigned long int n)
{
	int k, cnt = 0;
	unsigned long int curr;

	for (k = 63; k >= 0; k--)
	{
		curr = n >> i;

		if (curr & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}
