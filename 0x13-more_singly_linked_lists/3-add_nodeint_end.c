#include "lists.h"

/**
* add_nodeint_end - adds a node at end of list
* @head: points first element in the list
* @n: data to insert in the new nod
*
* Return: points new node, else NULL if it fails
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *neww;

	listint_t *tempp = *head;

	neww = malloc(sizeof(listint_t));
	if (!neww)
		return (NULL);

	neww->n = n;
	neww->next = NULL;
	if (*head == NULL)
	{
		*head = neww;
		return (neww);
	}
	while (tempp->next)
		tempp = tempp->next;
	tempp->next = neww;
	return (neww);
}
