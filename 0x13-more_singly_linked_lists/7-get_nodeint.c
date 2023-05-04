#include "lists.h"

/**
* get_nodeint_at_index - returns the node index in a lnkdlist
* @head: first node of lnkdlist
* @index: index of node to return
*
* Return: points node at index, or NULL
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int k = 0;

	listint_t *tempp = head;

	while (tempp && k < index)
	{
		tempp = tempp->next;
		k++;
	}
	return (tempp ? tempp : NULL);
}
