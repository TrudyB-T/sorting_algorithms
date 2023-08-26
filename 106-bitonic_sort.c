#include "sort.h"

/**
 * exchange - swaps two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void exchange(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}


/**
 * bitonic_compare - compares bitonically
 * @up: flag to indicate if sort phase is in ascending or
 * descending order
 * @array: array of integers
 * @right: right side index
 * @left: left side index
 */
void bitonic_compare(int up, int *array, size_t left, size_t right)
{
	size_t part = (right - left + 1) / 2, j;

	for (j = left; j < left + part; j++)
		if ((array[j] > array[j + part]) == up)
			exchange(&array[j], &array[j + part]);
}


/**
 * bitonic_merge - merges array
 * @up: flag to indicate if sort phase is in ascending
 * or descending order
 * @array: array of integers
 * @right: right side index
 * @left: left side index
 */

void bitonic_merge(int up, int *array, size_t left, size_t right)
{
	size_t mid = (left + right) / 2;

	if (right - left < 1)
		return;
	bitonic_compare(up, array, left, right);
	bitonic_merge(up, array, left, mid);
	bitonic_merge(up, array, mid + 1, right);
}


/**
 * recursive_bitonic - recursively creates and merges bitonis sequences
 * @up: flag to indicate if sort phase is in ascending or
 * descending order
 * @array: array of integers
 * @size: size of array
 * @right: right side index
 * @left: left side index
 */

void recursive_bitonic(int up, int *array, size_t size,
		size_t left, size_t right)
{
	size_t mid = (left + right) / 2;

	if (left - right < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", right - left + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + left, right - left + 1);
	recursive_bitonic(1, array, size, left, mid);
	recursive_bitonic(0, array, size, mid + 1, right);
	bitonic_merge(up, array, left, right);
	printf("Result [%lu/%lu] (%s):\n", right - left + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + left, right - left + 1);
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_bitonic(1, array, size, 0, size - 1);
}
