#include "lists.h"

/**
* sum_listint - sum of all the data in list
* @head: first node in the lnkdlist
*
* Return: sum
*/
int sum_listint(listint_t *head)
{
	int sum_num = 0;

	listint_t *tempp = head;

	while (tempp)
	{
		sum_num += tempp->n;
		tempp = tempp->next;
	}
	return (sum_num);
}
