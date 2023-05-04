#include "lists.h"
#include <stdio.h>

size_t looped_lstint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
* looped_lstint_len - Counts the num of unique nodes
* in a looped linked list.
* @head: A points head of the list to chck.
*
* Return: If list is not looped - 0.
* Otherwise - the num of unique nodes in list.
*/
size_t looped_lstint_len(const listint_t *head)
{
	const listint_t *tortoises, *hares;

	size_t nodess = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	tortoises = head->next;
	hares = (head->next)->next;
	while (hares)
	{
		if (tortoises == hares)
		{
			tortoises = head;
			while (tortoises != hares)
			{
				nodess++;
				tortoises = tortoises->next;
				hares = hares->next;
			}
			tortoises = tortoises->next;
			while (tortoises != hares)
			{
				nodess++;
				tortoises = tortoises->next;
			}
			return (nodess);
		}
		tortoises = tortoises->next;
		hares = (hares->next)->next;
	}
	return (0);
}
/**
* print_listint_safe - Prints a lnkdlist safely.
* @head: points head of list.
*
* Return: The num of nodes in list.
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t nodess, indx = 0;

	nodess = looped_lstint_len(head);
	if (nodess == 0)
	{
		for (; head != NULL; nodess++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (indx = 0; indx < nodess; indx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodess);
}
