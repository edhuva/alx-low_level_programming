#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node in lnkdlist index
* @head: points first element in list
* @index: index of node to delete
*
* Return: 1 (Success), or -1 (Fail)
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tempp = *head;
	listint_t *curr = NULL;
	unsigned int k = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(tempp);
		return (1);
	}
	while (k < index - 1)
	{
		if (!tempp || !(tempp->next))
			return (-1);
		tempp = tempp->next;
		k++;
	}
	curr = tempp->next;
	tempp->next = curr->next;
	free(curr);
	return (1);
}
