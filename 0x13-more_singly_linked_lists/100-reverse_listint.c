#include "lists.h"

/**
* reverse_listint - reverses a lnkdlist
* @head: pointfirst node in list
*
* Return: points first node in new list
*/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevv = NULL;
	listint_t *nxt = NULL;

	while (*head)
	{
		nxt = (*head)->next;
		(*head)->next = prevv;
		prevv = *head;
		*head = nxt;
	}
	*head = prevv;
	return (*head);
}
