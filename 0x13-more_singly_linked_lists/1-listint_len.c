#include "lists.h"

/**
* listint_len - returing number of elements in lists
* @h: linked list listint_t
*
* Return: num of nodes
*/
size_t listint_len(const listint_t *h)
{
	size_t num_int = 0;

	while (h)
	{
		num_int++;
		h = h->next;
	}
	return (num_int);
}
