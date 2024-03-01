#include "binary_trees.h"

/**
 * binary_tree_sibling - Function to find sibling of a node
 * @node: Pointer to the node
 * Return: Pointer to the sibling node otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
