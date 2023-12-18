#include "sort.h"

/**
 * heap_sort - heap_sort function
 * @array: arg1
 * @size: arg2
 *
 * Return: Nothing.
 **/
void heap_sort(int *array, size_t size)
{
	size_t i, s0 = size;
	int help;

	if (!array)
		return;
	for (i = 0; i < size / 2; i++)
		checker(array, s0, size, size / 2 - 1 - i);
	for (i = 0; i < s0 - 1; i++)
	{
		help = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = help;
		print_array(array, s0);
		checker(array, s0, size - i - 1, 0);
	}
}

/**
 * checker - checker function
 * @array: arg1
 * @s0: arg2
 * @size: arg3
 * @i: arg4
 *
 * Return: Nothing.
 **/
void checker(int *array, size_t s0, size_t size, size_t i)
{
	int help, part1, part2;
	size_t p1, p2;

	p1 = i * 2 + 1;
	p2 = p1 + 1;
	part1 = array[p1];
	part2 = array[p2];
	if ((p1 == size - 1 && part1 > array[i])
			|| (part1 >= part2 && part1 > array[i]
			&& p1 < size && p2 < size))
	{
		help = array[i];
		array[i] = part1;
		array[p1] = help;
		print_array(array, s0);
	}
	else if (part2 > part1 && part2 > array[i] && p1 < size && p2 < size)
	{
		help = array[i];
		array[i] = part2;
		array[p2] = help;
		print_array(array, s0);
	}
	if (p1 < size - 1)
		checker(array, s0, size, p1);
	if (p2 < size - 1)
		checker(array, s0, size, p2);
}

