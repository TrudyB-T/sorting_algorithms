#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	int n = 1, j, k;
	int temp;

	if (!array || !size || size < 2)
		return;
	while (n < (int)size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (j = n; j < (int)size; j++)
		{
			temp = array[j];
			k = j;
			while (k > (n - 1) && array[k - n] >= temp)
			{
				array[k] = array[k - n];
				k -= n;
			}
			array[k] = temp;
		}
		n = n / 3;
		print_array(array, size);
	}
}

