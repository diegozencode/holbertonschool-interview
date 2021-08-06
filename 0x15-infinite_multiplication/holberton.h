#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct add_node_s - linked list node for addition
 *
 * @add: Addition representation
 * @dig: Addition space
 * @space: Total space
 * @next: Pointer to the next node
 */
struct add_node_s
{
	char *add;
	int dig;
	int space;
	struct add_node_s *next;
};
typedef struct add_node_s add_node_t;

int _putchar(char c);

#endif /* HOLBERTON_H */
