#include "sort.h"

/**
 * merge_sort - sorts an array of integers using merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 **/
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return;

	merge_helper(array, size, tmp);
	free(tmp);
}

/**
 * merge_helper - helper function for merge_sort
 * @array: array of integers to sort
 * @size: size of the array
 * @tmp: temporary array
 **/
void merge_helper(int *array, size_t size, int *tmp)
{
	int middle;

	if (size < 2)
	{
		return;
	}

	middle = size / 2;
	merge_helper(array, middle, tmp);
	merge_helper(array + middle, size - middle, tmp);
	merge_sorting(array, size, middle, tmp);
}

/**
 * merge_sorting - sorts an array of integers using merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * @middle: middle index of the array
 * @tmp: temporary array
 **/
void merge_sorting(int *array, int size, int middle, int *tmp)
{
	int i;
	int j;
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);
	for (i = 0, j = middle, k = 0; k < size; k++)
	{
		if (j == size)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (i == middle)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
	}

	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	printf("[Done]: ");
	print_array(tmp, size);
}
