#include "binary_trees.h"
/**
 * binary_tree_is_avl - checks if a tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}

/**
 * is_avl - checks if a tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * @min: current minimun value
 * @max: current maximum value
 * @height: current height
 * Return: 1 if the tree is valid AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0;
	int h2 = 0;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!is_avl(tree->left, min, tree->n, &h1) ||
		!is_avl(tree->right, tree->n + 1, max, &h2))
		return (0);

	*height = MAX(h1, h2) + 1;

	return (ABS(h1 - h2) <= 1);
}
