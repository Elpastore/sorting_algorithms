#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s {
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next != NULL)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev != NULL)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
void printList(listint_t *head)
{
    while (head != NULL)
    {
        printf("%d ", head->n);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    
	listint_t *h = NULL;
	listint_t *node1, *node2, *node3;

    // Creating a sample doubly-linked list
    node1 = malloc(sizeof(listint_t));
    node2 = malloc(sizeof(listint_t));
    node3 = malloc(sizeof(listint_t));

    node1->n = 1;
    node1->prev = NULL;
    h = node1;
    node1->next = node2;


    node2->n = 2;
    node2->prev = node1;
    node2->next = node3;

    node3->n = 3;
    node3->prev = node2;
    node3->next = NULL;

    // Printing the original list
    printf("Original List: ");
    printList(h);

    // Swapping nodes
    swap_node(node2,&h);
    // Printing the list after swapping
    printf("List after swapping: ");
    printList(h);

    return 0;
}

