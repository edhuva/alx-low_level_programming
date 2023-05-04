#include "lists.h"

/**
* insert_nodeint_at_index - inserts a new node at indx in lnkdlist,
* @head:first node in the list
* @idx: index where new node is added
* @n: data to insert in new node
*
* Return: points new node, or NULL
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int k;
	listint_t *neww;

	listint_t *tempp = *head;

	neww = malloc(sizeof(listint_t));

	if (!neww || !head)
		return (NULL);

	neww->n = n;
	neww->next = NULL;
	if (idx == 0)
	{
		neww->next = *head;
		*head = neww;
		return (neww);
	}
	for (k = 0; tempp && k < idx; k++)
	{
		if (k == idx - 1)
		{
			neww->next = tempp->next;
			tempp->next = neww;
			return (neww);
		}
		else
			tempp = tempp->next;
	}
	return (NULL);
}
