#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new node at the right position
 * @head: pointer of the first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		if (current->n > new->n)
		{
			new->next = current;
			*head = new;
			return (*head);
		}
		else
		{
			while (current->next != NULL && current->next->n < new->n)
			{
				current = current->next;
			}
			new->next = current->next;
			current->next = new;
			return (new);
		}
	}
}
