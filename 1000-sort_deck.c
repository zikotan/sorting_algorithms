#include "deck.h"

/**
 * sort_deck - sort_deck function
 * @deck: arg1
 *
 * Return: Nothing.
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		sort1(deck);
		sort2(deck);
	}
}

/**
 * sort1 - sort1 function
 * @deck: arg1
 *
 * Return: Nothing.
 **/
void sort1(deck_node_t **deck)
{
	int f;
	deck_node_t *help1, *help2, *to1, *to2;

	if (deck)
	{
		help1 = *deck;
		help2 = *deck;
		while (deck && help1->next)
		{
			if (help1->next)
			{
				f = 0;
				help2 = help1;
				while (help2 && help2->card->kind > help2->next->card->kind)
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
						*deck = to2;
					f = 1;
				}
			}
			if (f == 0)
				help1 = help1->next;
		}
	}
}

/**
 * sort2 - sort2 function
 * @deck: arg1
 *
 * Return: Nothing.
 **/
void sort2(deck_node_t **deck)
{
	deck_node_t *help1, *help2, *to1, *to2;
	int f = 0, i, n1, n2;
	unsigned int k;

	help1 = *deck;
	help2 = *deck;
	for (i = 0; i < 4; i++)
	{
		k = help1->card->kind;
		while (help1->next && help1->next->card->kind == k)
		{
			n1 = nFunc(help1);
			n2 = nFunc(help1->next);
			f = 0;
			help2 = help1;
			while (help2 && help2->card->kind == k && n1 > n2)
			{
				to1 = help2;
				to2 = help2->next;
				to1->next = to2->next;
					if (to2->next)
						to2->next->prev = to1;
					to2->prev = to1->prev;
					to2->next = to1;
					to1->prev = to2;
					if (to2->prev)
						to2->prev->next = to2;
					help2 = to2->prev;
					if (!to2->prev)
						*deck = to2;
					f = 1;
					if (!help2)
						break;
					n1 = nFunc(help2);
					n2 = nFunc(help2->next);
			}
			if (f == 0)
				help1 = help1->next;
		} help1 = help1->next;
	}
}

/**
 * nFunc - nFunc function
 * @help1: arg1
 *
 * Return: Nothing.
 **/
int nFunc(deck_node_t *help1)
{
	int n, i;
	char C[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9',
		'1', 'J', 'Q', 'K'};
	int N[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	for (i = 0; i < 13; i++)
	{
		if (help1->card->value[0] == C[i])
			n = N[i];
	}
	return (n);
}
