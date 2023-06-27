#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	int *tmp, value;
	listint_t *current, *temp;

	if (!list)
		return;
	temp = (*list)->next;
	current = *list;
	while (temp)
	{
		current = temp;
		value = temp->n;
		while (current->prev && (current->prev->n > value))
		{
			tmp = (int *)&current->n;
			*tmp = current->prev->n;
			tmp = (int *)&current->prev->n;
			*tmp = value;
			print_list(*list);
			current = current->prev;
		}
		temp = temp->next;
	}
}
