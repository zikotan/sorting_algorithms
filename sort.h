#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define my_Up 0
#define my_Down 1

/**
 * enum my_Bool - my_Bool enumeration
 * @false: atr1
 * @true: atr2
 */
typedef enum my_Bool
{
	false = 0,
	true
} my_Bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void rec(int *array0, size_t s0, int *array, size_t size);
void shell_sort(int *array, size_t size);
void exchange1(listint_t **list, listint_t *help, listint_t *to);
void exchange2(listint_t **list, listint_t *help, listint_t *to);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merging(int *array, int *my_L, int *my_R, size_t size);
void merge_sort(int *array, size_t size);
void checker(int *array, size_t s0, size_t size, size_t i);
void heap_sort(int *array, size_t size);
int max(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif

