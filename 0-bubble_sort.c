#include "sort.h"

/**
 * bubble_sort - bubble_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, help;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				help = array[j];
				array[j] = array[j - 1];
				array[j - 1] = help;
				print_array(array, size);
			}
		}
	}
}

