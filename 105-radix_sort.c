#include "sort.h"

/**
 * radix_sort - radix_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void radix_sort(int *array, size_t size)
{
	int i, m, help = 1, s = size, *new;

	if (!array || size < 2)
		return;
	m = max(array, size);
	new = malloc(sizeof(int) * size);
	while (m / help > 0)
	{
		int thing[20] = {0};

		i = 0;
		while (i < s)
		{
			thing[(array[i] / help) % 10]++;
			i++;
		}
		if (thing != NULL)
		{
			for (i = 0; i < 10; i++)
				thing[i] = thing[i - 1];
			for (i = s - 1; i >= 0; i--)
			{
				new[thing[(array[i] / help) % 10] - 1] = array[i];
				thing[(array[i] / help) % 10]--;
			}
			for (i = 0; i < s; i++)
				array[i] = new[i];
		}
		help *= 10;
		print_array(array, size);
	}
	free(new);
}

/**
 * max - max function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
int max(int *array, size_t size)
{
	int m = array[0];
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > m)
			m = array[i];
	return (m);
}

