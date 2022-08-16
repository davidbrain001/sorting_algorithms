#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list using
 * the insertion algorithm
 * @list: pointer to first node of doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL;

	if (list == NULL || *list == NULL ||
			(*list)->next == NULL)
		return;
	node = (*list)->next;

	while (node != NULL)
	{
		while (node->prev != NULL && node->prev->n >
			       node->n)
		{
			swap(node, node->prev, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap - swaps a node with another
 * @n1: one of the odes to be swapped
 * @n2: the node n1 is to be swapped with
 * @list: pointer to first node of doubly linked list to be sorted
 */
void swap(listint_t *n1, listint_t *n2, listint_t **list)
{
	n2->next = n1->next;
	if (n1->next != NULL)
		n1->next->prev = n2;
	n1->next = n2;
	if (n2->prev)
		n2->prev->next = n1;
	else
	{
		*list = n1;
	}
	n1->prev = n2->prev;
	n2->prev = n1;
}
