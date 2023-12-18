#include "sort.h"

/**
 * bitonic_sort - bitonic_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive(array, size, 0, size, my_Up);
}

/**
 * recursive - recursive function
 * @array: arg1
 * @size: arg2
 * @start: arg3
 * @seq: arg4
 * @flow: arg5
 *
 * Return: Nothing.
 **/
void recursive(int *array, size_t size, size_t start, size_t seq, char flow)
{
	if (seq > 1)
	{
		size_t i, jump = seq / 2;
		char *str = (flow == my_Up) ? "UP" : "DOWN";

		printf("Merging [%lu/%lu] (%s):\n",
				(unsigned long)seq, (unsigned long)size, str);
		print_array(array + start, seq);
		recursive(array, size, start, jump, my_Up);
		recursive(array, size, start + jump, jump, my_Down);
		for (i = start; i < start + jump; i++)
		{
			int help = array[i];

			array[i] = (flow == my_Up && help > array[i + jump])
				? array[i + jump] : help;
			array[i + jump] = (flow == my_Up && help > array[i + jump])
				? help : array[i + jump];
		}

		printf("Result [%lu/%lu] (%s):\n", (unsigned long)seq,
				(unsigned long)size, str);
		print_array(array + start, seq);
	}
}

