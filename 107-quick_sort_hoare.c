#include "sort.h"

/**
 * exchange - swaps two integers
 * @array: array of integers
 * @size: size of the array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */

void exchange(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * hoare_partition - partitions the array using the haore technique
 * @array: array of integers
 * @size: size of array
 * @min: minimum element of the array
 * @max: maximum element of the array
 *
 * Return: size of array
 */

size_t hoare_partition(int *array, ssize_t size, ssize_t min,
		ssize_t max)
{
	ssize_t k = min - 1;
	ssize_t l = max + 1;
	int pivot = array[max];

	while (k < size)
	{
		while (array[++k] < pivot)
			;
		while (array[--l] > pivot)
			;
		if (k < l)
			exchange(array, size, &array[k], &array[l]);
		else if (k >= l)
			break;
	}
	return (k);
}


/**
 * quicksort - sorts an array of integers
 * using quick sort algorithm
 * @array: array of integers
 * @size: size of array
 * @min: minimum element of the array
 * @max: maximum element of the array
 */

void quicksort(int *array, size_t size, ssize_t min, ssize_t max)
{
	ssize_t q = 0;

	if (min < max)
	{
		q = hoare_partition(array, size, min, max);

		quicksort(array, size, min, q - 1);
		quicksort(array, size, q, max);
	}
}


/**
 * quick_sort_hoare - array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
