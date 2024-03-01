#include "binary_trees.h"

/**
 * binary_tree_inorder - Function that traverses a tree using in-order
 * @tree: pointer to the root of tree node
 * @func: pointer to function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}