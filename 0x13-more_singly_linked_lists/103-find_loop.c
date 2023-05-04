#include "lists.h"

/**
* find_listint_loop - finds loop in a lnkdlist
* @head: lnkdlist to search for
*
* Return: address of node where the loop begins, or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sloww = head;
	listint_t *fasst = head;

	if (!head)
		return (NULL);

	while (sloww && fasst && fasst->next)
	{
		fasst = fasst->next->next;
		sloww = sloww->next;
		if (fasst == sloww)
		{
			sloww = head;
			while (sloww != fasst)
			{
				sloww = sloww->next;
				fasst = fasst->next;
			}
			return (fasst);
		}
	}
	return (NULL);
}
