#include "sort.h"

/**
 * cocktail_sort_list - cocktail_sort_list function
 * @list: arg1
 *
 * Return: Nothing.
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *help, *to;
	int f = 1;

	if (list)
	{
		help = *list;
		while (f != 0)
		{
			f = 0;
			while (help->next)
			{
				if (help->n > help2->next->n)
				{
					to = help->next;
					exchange1(list, help, to);
					f = 1;
				}
				else
					help  = help->next;
			}
			if (f == 0)
				break;
			f = 0;
			while (help->prev)
			{
				if (help->prev->n > help->n)
				{
					exchange2(list, help, to);
					f = 1;
				}
				else
					help = help->prev;
			}
		}
	}
}

/**
 * exchange1 - exchange1 function
 * @list: arg1
 * @help: arg2
 * @to: arg3
 *
 * Return: Nothing.
 **/
void exchange1(listint_t **list, listint_t *help, listint_t *to)
{
	if (help->prev)
		help->prev->next = to;
	else
		*list = to;
	if (to->next)
		to->next->prev = help;
	help->next = to->next;
	to->prev = help->prev;
	to->next = help;
	help->prev = to;
	print_list(*list);
}

/**
 * exchange2 - exchange2 function
 * @list: arg1
 * @help: arg2
 * @to: arg3
 *
 * Return: Nothing.
 **/
void exchange2(listint_t **list, listint_t *help, listint_t *to)
{
	to = help->prev;
	to->next->prev = to->prev;
	if (to->prev)
		to->prev->next = to->next;
	else
		*list = to->next;
	to->prev = to->next;
	to->next = to->next->next;
	to->prev->next = to;
	if (to->next)
		to->next->prev = to;
	print_list(*list);
}

