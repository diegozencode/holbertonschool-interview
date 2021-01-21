#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is palindrome
 * @head: double pointer to the head of list
 * Return: 1 if it is palindrome, 0 if it is not
 */
int is_palindrome(listint_t **head)
{
	int i = 1;
	int n_nodes = 1;
	int val = 0;
	listint_t *current = *head;
	listint_t *init = *head;
	listint_t *tmp = *head;

	if (*head == NULL)
		return (1);

	while (current->next != NULL)
	{
		n_nodes = n_nodes + 1;
		current = current->next;
	}

	if (init->n != current->n)
		return (0);

	while (i <= n_nodes)
	{
		val = util_palindrome(&tmp, n_nodes - i);
		if (init->n != val)
			return (0);
		init = init->next;
		i++;
	}

	return (1);
}

/**
 * util_palindrome - check value of given position
 * @head: double pointer to the head of list
 * @node: position of node
 * Return: value of given node
 */
int util_palindrome(listint_t **head, int node)
{
	listint_t *current = *head;
	int i = 1;

	while (i <= node)
	{
		current = current->next;
		i++;
	}

	return (current->n);
}
