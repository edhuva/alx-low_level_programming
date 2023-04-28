#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * @head: double pointer to the list_t
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *tempp = *head;
	unsigned int length = 0;

	while (str[length])
		length++;
	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->len = length;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (tempp->next)
		tempp = tempp->next;
	tempp->next = new;
return (new);
}
