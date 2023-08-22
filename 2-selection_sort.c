#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts array of integers, ascending order using Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */


void selection_sort(int *array, size_t size)
{
size_t i, j, min_idx;

if (array == NULL || size < 2)
return;

	for (i = 0; i < size - 1; i++)
	{
	min_idx = i;

	/* Find the index of the minimum element in the unsorted portion */
	for (j = i + 1; j < size; j++)
	{
	if (array[j] < array[min_idx])
	min_idx = j;
}

/* Swap the minimum element with the current element if necessary */
if (min_idx != i)
{
	int temp = array[i];

	array[i] = array[min_idx];

	array[min_idx] = temp;

/* Print the array after each swap */
print_array(array, size);
}
}
}
