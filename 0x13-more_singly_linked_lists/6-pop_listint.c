#include "lists.h"

/**
* pop_listint - deletes the head node of list
* @head: points first element in the linkd list
*
* Return: the data of the node that was deleted,
* or 0 if list is empty
*/
int pop_listint(listint_t **head)
{
	listint_t *tempp;
	int numm;

	if (!head || !*head)
		return (0);
	numm = (*head)->n;
	tempp = (*head)->next;
	free(*head);
	*head = tempp;
	return (numm);
}
