#include <stdlib.h>
#include "lnklists.h"

/**
 * list_len - returns the number of elements
 * @h: pointer to the list_t
 *
 * Return: number of elements
 */

size_t list_len(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		k++;
		h = h->next;
	}

return (k);
}

