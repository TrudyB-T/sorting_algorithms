#include "sort.h"

/**
 * _swap - exchanges integers
 * @c: pointer to first integer
 * @d: pointer to second integer
 */

void _swap(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * partition - Using a pivot, partition an array.
 * @array: Array of integers
 * @low: integer
 * @high: integer
 * @size: Array size
 * Return: pivot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			i++;
			if (i != y)
			{
				_swap(&array[i], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (i);
}
/**
 * lomuto_qsort - an array recursively sorted
 * @array:  sorted array
 * @low: lowest array value
 * @high: highest array value
 * @size: Array size
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int y;

	if (low < high)
	{
		y = partition(array, low, high, size);
		lomuto_qsort(array, low, y - 1, size);
		lomuto_qsort(array, y + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: an array of integers
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
