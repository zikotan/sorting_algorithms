#include "sort.h"

/**
 * counting_sort - counting_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int n, j, *c_Array, *to;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	}
	c_Array = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		c_Array[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		c_Array[j + 1] += c_Array[j];
	}
	print_array(c_Array, n + 1);
	to = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		c_Array[array[i]]--;
		to[c_Array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = to[i];
	}
	free(to);
	free(c_Array);
}

