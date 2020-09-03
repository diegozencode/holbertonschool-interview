#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * build_max_heap - top to bottom heap
 * @array: array of integers
 * @size: size of the array
 * @index: position in the array
 */
void build_max_heap(int *array, size_t size, size_t index)
{
	size_t max = index;
	size_t left_child = (2 * index) + 1;
	size_t right_child = (2 * index) + 2;

	if (left_child < size && array[left_child] > array[max])
	{
		max = left_child;
	}

	if (right_child < size && array[right_child] > array[max])
	{
		max = right_child;
	}

	if (max != index)
	{
		int temp = array[index];

		array[index] = array[max];
		array[max] = temp;
		/*print_array(array, size);*/
		build_max_heap(array, size, max);
	}
}

/**
 * heap_sort - sorts an array in ascending order using heap sort
 * @array: array of integers
 * @size: lenght of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return;
	}

	if (size < 2)
	{
		print_array(array, size);
	}

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		build_max_heap(array, size, i);
	}

	for (size_t i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		build_max_heap(array, i, 0);
	}
}
