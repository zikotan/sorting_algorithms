#include "sort.h"

/**
 * selection_sort - selection_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k, n;
	int to, f;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			to = array[i];
			f = 0;
			for (j = i; j < size; j++)
			{
				if (array[j] < to)
				{
					k = j;
					to = array[j];
					f = 1;
				}
			}
			if (f == 1)
			{
				n = array[i];
				array[i] = array[k];
				array[k] = n;
				print_array(array, size);
			}
		}
	}
}

