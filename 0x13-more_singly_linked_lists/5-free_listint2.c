#include "lists.h"

/**
* free_listint2 - freeing linked list
* @head: points listint_t list to free
*/
void free_listint2(listint_t **head)
{
	listint_t *tempp;

	if (head == NULL)
		return;
	while (*head)
	{
		tempp = (*head)->next;
		free(*head);
		*head = tempp;
	}
	*head = NULL;
}
