#include "binary_trees.h"
/**
 * binary_trees_insert_right - Function to insert a node as right child
 * @parent: Parent of the node
 * @value: Value of the node
 * Return: Pointer to the node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new =  binary_tree_node(parent, value);
	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;
	return (new);
}
