#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linkedlist
 * @h: pointer to the list_t
 *
 * Return: number of nodes print
 */

size_t print_list(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		k++;
	}
return (k);
}
