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
	int swap, count, flag, i;

	if (*list == NULL)
		return;

	beg = *list;
	swap = 1;
	count = 0;
	i = 0;

	while (swap == 1)
	{
		swap = 0;
		trav = beg;

		while (trav->next)
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
				{
					trav->prev->next = tmp;
					trav->prev = tmp;
				}
				swap = 1;
				print_list(*list);
				count++;
			}
			else
			{
				trav = trav->next;
				count++;
			}
			if (count == flag && (i != 0))
				break;
		}

		if (i == 0)
			flag = count;
		i = 1;

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
				count--;
			}
			else
			{
				trav = trav->prev;
				count--;
			}
			if (count == 0)
			{
				flag -= 1;
				break;
			}
		}
		beg = trav;
	}
}
