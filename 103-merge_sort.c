#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * amalgamate_subarray - amalgamates subarrays
 * @sub: subarray of integers
 * @buff: storage buffer
 * @left: index of the array on the left
 * @mid: index of the array in the mid-section
 * @right: index of the array on the right
 */

void amalgamate_subarray(int *sub, int *buff, size_t left,
		size_t mid, size_t right)
{
	size_t p, q, r = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + left, mid - left);

	printf("[right]: ");
	print_array(sub + mid, right - mid);

	for (p = left, q = mid; p < mid && q < right; r++)
		buff[r] = (sub[p] < sub[q]) ? sub[p++] : sub[q++];
	for (; p < mid; p++)
		buff[r++] = sub[p];
	for (; q < right; q++)
		buff[r++] = sub[q];
	for (p = left, r = 0; p < right; p++)
		sub[p] = buff[r++];

	printf("[Done]: ");
	print_array(sub + left, right - left);
}

/**
 * merge_sort_recursive - perform merge sort to sucessive results
 * @sub: subarray of integers
 * @buff: storage buffer
 * @left:left side of array
 * @right: right side of array
 */

void merge_sort_recursive(int *sub, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(sub, buff, left, mid);
		merge_sort_recursive(sub, buff, mid, right);
		amalgamate_subarray(sub, buff, left, mid, right);
	}
}


/**
 * merge_sort -  sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

