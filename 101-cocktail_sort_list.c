#include "sort.h"

/**
* cocktail_sort_list - This sorts a doubly linked list of integers in
* an ascending
* order using cocktail sort
* @list: linked list to be sorted
* Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *beg, *trav, *tmp;
	int swap;

	if (*list == NULL)
		return;

	beg = *list;
	swap = 1;

	while (swap == 1)
	{
		swap = 0;
		trav = beg;

		while (trav->next != NULL)
		{
			if (trav->n > trav->next->n)
			{
				tmp = trav->next;
				trav->next = tmp->next;
				if (trav->next != NULL)
					trav->next->prev = trav;
				tmp->next = trav;
				tmp->prev = trav->prev;

				if (trav->prev != NULL)
					trav->prev->next = tmp;

				else if (trav->prev == NULL)
					*list = tmp;

				trav->prev = tmp;
				swap = 1;
				print_list(*list);
			}
			else
				trav = trav->next;
		}

		while (trav->prev != NULL)
		{
			if (trav->n < trav->prev->n)
			{
				tmp = trav->prev;
				trav->prev = tmp->prev;
				if (trav->prev != NULL)
					trav->prev->next = trav;
				else if (trav->prev == NULL)
					*list = trav;
				tmp->prev = trav;
				tmp->next = trav->next;

				if (trav->next != NULL)
				{
					trav->next->prev = tmp;
					trav->next = tmp;
				}
				swap = 1;
				print_list(*list);
			}
			else
				trav = trav->prev;
		}
		beg = trav;
	}
}
