#include "sort.h"

/**
 * quick_sort - quick_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void quick_sort(int *array, size_t size)
{
	size_t s0;
	int *array0;

	if (array)
	{
		array0 = array;
		s0 = size;
		rec(array0, s0, array, size);
	}
}

/**
 * rec - rec function
 * @array0: arg1
 * @s0: arg2
 * @array: arg3
 * @size: arg4
 *
 * Return: Nothing.
 **/
void rec(int *array0, size_t s0, int *array, size_t size)
{
	size_t i, to1;
	int j = -1, n, p = array[size - 1];
	int to2;

	if (array && size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] < p)
			{
				j++;
				to1 = j;
				if (to1 != i && array[i] != array[to1])
				{
					n = array[i];
					array[i] = array[j];
					array[j] = n;
					print_array(array0, s0);
				}
			}
		}
		to2 = size;
		if (to2 - 1 != j + 1 && array[to2 - 1] != array[j + 1])
		{
			array[size - 1] = array[j + 1];
			array[j + 1] = p;
			print_array(array0, s0);
		}
		if (j > 0)
		{
			rec(array0, s0, array, j + 1);
		}
		rec(array0, s0, array + j + 2, size - (j + 2));
	}
}
