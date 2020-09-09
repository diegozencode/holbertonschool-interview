#include "search_algos.h"
/**
 * advanced_binary - searches a value in an array of integers
 * @array: pointer to the first element
 * @size: number of elements in array
 * @value: the value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int left = 0;
	int right = 0;
	int index = 0;

	if (array == NULL || size == 0)
		return (-1);

	right = (int)size;
	index = binary_search(array, left, right, value);
	return (index);
}

/**
 * binary_search - recursive search
 * @array: pointer to the first element
 * @left: first element
 * @right: last element
 * @value: the value to search for
 * Return: index
 */
int binary_search(int *array, int left, int right, int value)
{
	printf("Searching in array: ");
	for (int i = left; i < right; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	if (left > right)
		return (-1);

	int mid = (left + right) / 2;

	if (value == array[mid])
		return (mid);
	else if (value < array[mid])
		return (binary_search(array, left, mid - 1, value));
	else
		return (binary_search(array, mid + 1, right, value));
}
