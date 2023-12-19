#include "sort.h"

/**
 * quick_sort_hoare - quick_sort_hoare function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	version(array, 0, size - 1, size);
}

/**
 * version - version function
 * @array: arg1
 * @start: arg2
 * @finish: arg3
 * @size: arg4
 *
 * Return: Nothing.
 **/
void version(int *array, ssize_t start, ssize_t finish, int size)
{
	ssize_t pos = 0;
	int now, exist, p, help;

	if (start < finish)
	{
		now = start - 1;
		exist = finish + 1;
		p = array[finish];
		while (1)
		{
			do
				now++;
			while (array[now] < p);
			do
				exist--;
			while (array[exist] > p);
			if (now >= exist)
			{
				pos = now;
				break;
			}
			help = array[now];
			array[now] = array[exist];
			array[exist] = help;
			print_array(array, size);
		}
		version(array, start, pos - 1, size);
		version(array, pos, finish, size);
	}
}

