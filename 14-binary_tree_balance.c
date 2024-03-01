#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL otherwise balnca factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree
 * Return: 0 if tree is NULL otherwise height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_s = 0, right_s = 0;

		left_s = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_s = tree->right ? 1 + binary_tree_height(tree->right)
			: 1;
		return ((left_s > right_s) ? left_s : right_s);
	}
	return (0);
}
