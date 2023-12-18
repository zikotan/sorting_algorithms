#include "sort.h"

/**
 * merge_sort - merge_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void merge_sort(int *array, size_t size)
{
	size_t i, center = 0;
	int my_L[1000], my_R[1000];

	if (!array || size < 2)
		return;
	center = size / 2;
	for (i = 0; i < center; i++)
		my_L[i] = array[i];
	for (i = center; i < size; i++)
		my_R[i - center] = array[i];
	merge_sort(my_L, center);
	merge_sort(my_R, size - center);
	merging(array, my_L, my_R, size);
}

/**
 * merging - merging function
 * @array: arg1
 * @my_L: arg2
 * @my_R: arg3
 * @size: arg4
 *
 * Return: Nothing.
 **/
void merging(int *array, int *my_L, int *my_R, size_t size)
{
	int i = 0, j = 0, k = 0, sl, sr;

	sl = size / 2;
	sr = size - sl;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(my_L, sl);
	printf("[right]: ");
	print_array(my_R, sr);
	while (i < sl && j < sr)
	{
		if (my_L[i] < my_R[j])
			array[k++] = my_L[i++];
		else
			array[k++] = my_R[j++];
	}
	while (i < sl)
		array[k++] = my_L[i++];
	while (j < sr)
		array[k++] = my_R[i++];
	printf("[Done]: ");
	print_array(array, size);
}

