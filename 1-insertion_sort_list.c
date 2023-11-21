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
 * insertion_sort_list - sorts a doubly linked list using insertion sort algo
 * @list: pointer to the head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			swap_node(list, prev);
			print_list(*list);

			prev = temp->prev;
		}
		current = current->next;
	}
}
