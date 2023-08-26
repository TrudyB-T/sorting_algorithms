#include "sort.h"

/**
 * _getint - gets a digit from integer
 * @num: integer
 * @digit: position of digit to get
 *
 * Return: value of digit
 */

int _getint(long num, int digit)
{
	long j = 0L, pow = 1L, result;

	for (j = 0; j < digit; j++)
		pow *= 10L;
	result = ((num / pow) % 10);
	return (result);
}

/**
 * radix_pass - performs one pass of radix sort
 * @array: array of integers
 * @size: size of array
 * @digit: current digit position
 * @new_array: target array of same size to store sorted integers
 *
 *Return: 1 on sucess and 0 on failure
 */

int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t j;
	int count[10] = {0};

	for (j = 0; j < size; j++)
		count[_getint(array[j], digit)]++;
	for (j = 1; j <= 9; j++)
		count[j] += count[j - 1];
	for (j = size - 1; j > -1; j--)
		new_array[count[_getint(array[j], digit)]-- - 1] = array[j];
	return (1);
}

/**
 * radix_sort -  sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @size: size of the array
 * @array: array of integers
 */

void radix_sort(int *array, size_t size)
{
	int *array1, *array2, *ptr1, *ptr, big = 0;
	size_t j, k = 1;

	if (!array || size < 2)
		return;

	for (j = 0; j < size; j++)
		if (array[j] > big)
			big = array[j];
	while (big /= 10)
		k++;
	array1 = array;
	array2 = ptr = malloc(sizeof(int) * size);
	if (!array2)
		return;
	for (j = 0; j < k; j++)
	{
		radix_pass(array1, (ssize_t)size, j, array2);
		ptr1 = array1;
		array1 = array2;
		array2 = ptr1;
		print_array(array1, size);
	}
	for (j = 0; j < size; j++)
		array[j] = array1[j];
	free(ptr);
}
