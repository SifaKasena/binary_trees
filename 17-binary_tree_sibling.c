#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node to find sibling for
 * Return: pointer to the sibling, NULL if:
 *         -node is NULL
 *         -parent is NULL
 *         -node has no sibling
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;

	if (parent->left)
		return (parent->left != node ? parent->left : parent->right);

	return (NULL);
}
