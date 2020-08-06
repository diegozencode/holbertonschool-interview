#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the array to convert
 * @size: number of elements in the array
 * Return: a pointer to the new AVL tree or Null if it fails
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head = NULL;
	int top = 0;

	if (!array || !size)
		return (NULL);

	if (size % 2 == 0)
		top = ((int)size / 2) - 1;
	else
		top = (int)size / 2;

	head = binary_tree_node(array[top]);
	return (head);
}

/**
 * binary_tree_node - create new node
 * @value: value to enter in the node
 * Return: new node of NULL if it fails
 */
avl_t *binary_tree_node(int value)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->parent = NULL;
	new_node->right = NULL;

	return (new_node);
}
