#include "hls.h"
/**
*add_node - 0
*
*@head: list_t
*@str: char *
*Return: list_t
*
*/
Node_t *add_node(Node_t **head, const char *str)
{
	Node_t *new = NULL, *h = NULL;

	new = malloc(sizeof(Node_t));
	if (new == NULL)
	{
		return (NULL);
	}
	(*new).str = malloc(sizeof(str));
	_strcpy((*new).str, str);
	(*new).len = _strlen(str);
	(*new).next = NULL;
	h = *head;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while ((*h).next != NULL)
			h = (*h).next;
		(*h).next = new;
	}
	return (*head);

}
/**
*free_list - 0
*
*@h: list_t
*/
void free_list(Node_t *h)
{
	Node_t *next = NULL;

	while (h != NULL)
	{
		next = (*h).next;
		free((*h).str);
		free(h);
		if (next == NULL)
			h = NULL;
		else
			h = next;
	}
	free(h);
	free(next);
}
