#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t b, c;
	int d;

	if (size < 2)
		return;
	for (c = 0; c < size - 1; c++)
	{
		for (b = 0; b < size - c - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				d = array[b];
				array[b] = array[b + 1];
				array[b + 1] = d;
				print_array(array, size);
			}
		}
	}
}
