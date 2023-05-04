#include "lists.h"

/**
* print_listint - prints elements in linked list
* @h: linked list listint_t
*
* Return: number of the nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t num_int = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num_int++;
		h = h->next;
	}
	return (num_int);
}
