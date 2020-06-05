#include "lists.h"

/**
 * check_cycle - checks if a single linked list has a cycle
 * @list: head pointer
 * Return: 0 if there is no cycle and 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *hare = list;
	listint_t *tortoise = list;

	if (list)
	{
		while (hare->next)
		{
			hare = hare->next;
			if (!hare->next)
				return (0);
			hare = hare->next;
			tortoise = tortoise->next;
			if (hare == tortoise)
				return (1);
		}
	}
	return (0);
}
