#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t
 */

void free_list(list_t *head)
{
	list_t *tempp;

	while (head)
	{
		tempp = head->next;
		free(head->str);
		free(head);
		head = tempp;
	}
}
