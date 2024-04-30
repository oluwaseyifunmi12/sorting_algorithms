#include "sort.h"

/**
 * insertion_sort_list - arranges a doubly linked in ascending order
 * @list: Pointer to the head of the list
 *
 * returns the array after each swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *present, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	present = (*list)->next;

	while (present != NULL)
	{
		insert = present->prev;
		temp = present;

		while (insert != NULL && insert->n > temp->n)
		{

			if (insert->prev != NULL)
				insert->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = insert;

			insert->next = temp->next;
			temp->prev = insert->prev;

			temp->next = insert;
			insert->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			insert = temp->prev;

			print_list(*list);
		}
		present = present->next;
	}
}
