#include "sort.h"

/**
 * insertion_sort_list - insertion_sort_list function
 * @list: arg1
 *
 * Return: Nothing.
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *help1, *help2, *to1, *to2;
	int f;

	if (list)
	{
		help1 = *list;
		help2 = *list;
		while (list && help1->next)
		{
			if (help1->next)
			{
				f = 0;
				help2 = help1;
				while (help2 && help2->n > help2->next->n)
				{
					to1 = help2;
					to2 = help2->next;
					to1->next = to2->next;
					if (to2->next)
						to2->next->prev = to1;
					if (to2)
					{
						to2->prev = to1->prev;
						to2->next = to1;
					}
					if (to1)
						to1->prev = to2;
					if (to2->prev)
						to2->prev->next = to2;
					help2 = to2->prev;
					if (!to2->prev)
						*list = to2;
					print_list(*list);
					f = 1;
				}
			}
			if (f == 0)
				help1 = help1->next;
		}
	}
}

