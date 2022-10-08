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
	listint_t *tmp = NULL, *ins_node = NULL, *trav = NULL;

	tmp = *list;
	while (tmp && tmp->next)
	{
		if ((tmp->n) > (tmp->next->n))
		{
			ins_node = tmp->next;
			tmp->next = ins_node->next;

			if (ins_node->next != NULL)
				ins_node->next->prev = tmp;

			trav = *list;
			while (trav->n <= ins_node->n)
			{
				trav = trav->next;
			}
			ins_node->prev = trav->prev;

			if (trav->prev != NULL)
				trav->prev->next = ins_node;

			ins_node->next = trav;
			trav->prev = ins_node;

			if (ins_node->prev == NULL)
				*list = ins_node;

			print_list(*list);
		}
		else
			tmp = tmp->next;
	}
}
