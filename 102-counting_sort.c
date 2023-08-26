#include "sort.h"

/**
 * get_max - Value of Interger in array
 * @array: Array of int
 * @size: Array size
 *
 * Return: Max int in array
 */

int get_max(int *array, int size)
{
	int mat, y;

	for (mat = array[0], y = 1; y < size; y++)
	{
		if (array[y] > mat)
			mat = array[y];
	}

	return (mat);
}

/**
 * counting_sort - Integer array sort in ascending order.
 *  Sort using counting algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Description: After setting up the counting array, it prints.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, mat, y;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	mat = get_max(array, size);
	count = malloc(sizeof(int) * (mat + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (y = 0; y < (mat + 1); y++)
		count[y] = 0;
	for (y = 0; y < (int)size; y++)
		count[array[y]] += 1;
	for (y = 0; y < (mat + 1); y++)
		count[y] += count[y - 1];
	print_array(count, mat + 1);

	for (y = 0; y < (int)size; y++)
	{
		sorted[count[array[y]] - 1] = array[y];
		count[array[y]] -= 1;
	}

	for (y = 0; y < (int)size; y++)
		array[y] = sorted[y];

	free(sorted);
	free(count);
}
