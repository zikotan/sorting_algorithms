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
	sequence(array, size, 0, size, my_Up);
}

/**
 * sequence - sequence function
 * @array: arg1
 * @size: arg2
 * @begin: arg3
 * @s: arg4
 * @f: arg5
 *
 * Return: Nothing.
 **/
void sequence(int *array, size_t size, size_t begin, size_t s, char f)
{
	size_t c = s / 2;
	char *str = (f == my_Up) ? "UP" : "DOWN";

	if (s > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", (unsigned long)s,
				(unsigned long)size, str);
		print_array(array + begin, s);
		sequence(array, size, begin, c, my_Up);
		sequence(array, size, begin + c, c, my_Down);
		merge(array, size, begin, s, f);
		printf("Result [%lu/%lu] (%s):\n",
				(unsigned long)s, (unsigned long)size, str);
		print_array(array + begin, s);
	}
}

/**
 * merge - merge function
 * @array: arg1
 * @size: arg2
 * @begin: arg3
 * @s: arg4
 * @f: arg5
 *
 * Return: Nothing.
 **/
void merge(int *array, size_t size, size_t begin, size_t s, char f)
{
	size_t i, c = s / 2;
	int help;

	if (s > 1)
	{
		for (i = begin; i < begin + c; i++)
		{
			if ((f == my_Up && array[i] > array[i + c])
				|| (f == my_Down && array[i] < array[i + c]))
				{
					help = *(array + i);
					*(array + i) = *(array + i + c);
					*(array + i + c) = help;
				}
		}
		merge(array, size, begin, c, f);
		merge(array, size, begin + c, c, f);
	}
}
