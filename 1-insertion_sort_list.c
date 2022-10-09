#include "sort.h"

/**
* insertion_sort_list - sorts a doublylinkedly linked list
* in ascending order using insertion sort algorithm
* insertion sort algirithm
* @list: pointer to the beginning of list to be sorted
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *trav = NULL, *curr = NULL;

	if (*list || list)
		tmp = *list;

	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			trav = tmp->next;
			while (trav != NULL)
			{
				trav = trav->prev;
				if (trav != NULL && (trav->n > trav->next->n))
				{
					curr = trav->next;
					trav->next = curr->next;
					if (curr->next != NULL)
						curr->next->prev = trav;

					curr->next = trav;
					if (trav->prev != NULL)
						trav->prev->next = curr;
					curr->prev = trav->prev;
					trav->prev = curr;
					if (curr->prev == NULL)
						*list = curr;

					print_list(*list);
					trav = curr;
				}
				else
					break;
			}
		}
		else
			tmp = tmp->next;
	}
}
