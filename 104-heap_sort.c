#include "sort.h"

/**
 * rearrange_tree - rearranges tree branches
 * @array: array of integers
 * @size_init: initial array size
 * @size: size of array
 * @j: index of the current node in binary tree to reaarrange
 */

void rearrange_tree(int *array, size_t size_init, size_t size, size_t j)
{
	size_t br1 = j * 2 + 1;
	size_t br2 = br1 + 1;
	int branch1, branch2, o;

	branch1 = array[br1];
	branch2 = array[br2];

	if (((br1 < size) && (br2 < size) &&
		(branch1 >= branch2 && branch1 > array[j]))
		|| ((br1 == size - 1) && branch1 > array[j]))
	{
		o = array[j];
		array[j] = branch1;
		array[br1] = o;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(branch2 > branch1 && branch2 > array[j]))
	{
		o = array[j];
		array[j] = branch2;
		array[br2] = o;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		rearrange_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		rearrange_tree(array, size_init, size, br2);
}

/**
 * heap_sort -  sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t j = 0, size_init = size;
	int o;

	if (array == NULL)
		return;

	for (; j < size / 2 ; j++)
	{
		rearrange_tree(array, size_init, size, (size / 2 - 1) - j);
	}
	for (j = 0; j < size_init - 1; j++)
	{
		o = array[0];
		array[0] = array[size - 1 - j];
		array[size - 1 - j] = o;
		print_array(array, size_init);
		rearrange_tree(array, size_init, size - j - 1, 0);
	}

}
