#include "sort.h"
/**
 * swap_node - swap a two node
 * @list: head of linked list
 * @node: node to be swapped
 */
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->prev != NULL)
		node->prev->next = node->next;

	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next != NULL)
		node->next->prev = node;
}
/**
 * cocktail_sort_list - sort a linked list using cocktail sort
 * @list: head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_node(list, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_node(list, current->prev);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
