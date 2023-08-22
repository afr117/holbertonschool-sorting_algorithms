#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The partition index.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if ((i + 1) != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    size_t p_idx;

    if (low < high)
    {
        p_idx = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, p_idx - 1, size);
        quick_sort_recursive(array, p_idx + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

