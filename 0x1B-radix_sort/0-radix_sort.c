#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using radix sort
 * @array: array of integers to sort
 * @size: size of the array to sort
 * Return: Void
 **/
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = INT_MIN;
	int *arr;
	long exp;

	if (!array || size <= 2)
	{
		return;
	}

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;

	for (i = 0; i < size; i++)
	{
		max = array[i] > max ? array[i] : max;
	}
	for (exp = 1; max / exp > 0; exp *= RADIX)
	{
		count_sort(array, size, arr, exp);
		print_array(array, size);
	}
	free(arr);
}

/**
 * count_sort - counts the number of times each element appears in the array
 * @array: array of integers to sort
 * @size: size of the array to sort
 * @arr: array of counts
 * @exp: the exponent to count
 * Return: count
 **/
int count_sort(int *array, ssize_t size, int *arr, long exp)
{
	ssize_t i;
	int count[RADIX] = {0};
	int ret = 0;

	for (i = 0; i < size; i++)
	{
		count[array[i] / exp % RADIX]++;
		arr[i] = 0;
	}
	for (i = 1; i < RADIX; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		arr[--count[(array[i] / exp) % RADIX]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = arr[i];
	}

	return (ret);
}
