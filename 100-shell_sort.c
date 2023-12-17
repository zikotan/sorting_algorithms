#include "sort.h"

/**
 * shell_sort - shell_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void shell_sort(int *array, size_t size)
{
	size_t i, j = 0, k = 0, shell[1000];
	int n, m;

	if (!array)
		return;
	while (j * 3 + 1 < size)
	{
		shell[k] = j * 3 + 1;
		j = shell[k++]
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (j + shell[k - i - 1] > size - 1)
				break;
			m = j;
			while (array[m] > array[m + shell[k - i - 1]])
			{
				n = array[m];
				array[m] = array[m + shell[k - i - 1];
				array[m + shell[k - i - 1] = n;
				m = m - shell[k - i - 1];
				if (m < 0)
					break
			}
		}
		print_array(array, size);
	}
}

