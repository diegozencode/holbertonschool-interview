#include "search.h"

/**
 * linear_skip - linear search in a skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: a pointer on the first node where value is located or NULL on fail
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express = NULL;

	if (list == NULL || value == 0)
	{
		return (NULL);
	}
	else
	{
		express = list->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

		while (express && express->n < value)
		{
			list = express;
			express = express->express;
			if (express == NULL)
			{
				break;
			}

			printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		}

		return (list);
	}
}
