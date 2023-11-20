#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort algo
 * @list: pointer to the head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (!*list || !(*list)->next)
		return;
	current = *list;
	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = prev;

			temp->prev = prev->prev;
			prev->next = temp->next;
			temp->next = prev;
			prev->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);

			prev = temp->prev;
		}
		current = current->next;
	}
}
