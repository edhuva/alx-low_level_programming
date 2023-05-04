#include "lists.h"

/**
* free_listint_safe - frees a lnkdlist
* @h: points first node in lnkdlist
*
* Return: num of nodes freed in list
*/
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int difff;
	listint_t *tempp;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		difff = *h - (*h)->next;
		if (difff > 0)
		{
			tempp = (*h)->next;
			free(*h);
			*h = tempp;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}
	*h = NULL;
	return (length);
}
