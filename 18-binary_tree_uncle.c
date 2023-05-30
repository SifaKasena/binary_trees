#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: node to find incle for
 * Return: pointer to the uncle, NULL if:
 *         -node is NULL
 *         -node has no uncle
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_p;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (!parent || !parent->parent)
		return (NULL);

	grand_p = parent->parent;

	if (grand_p->left)
		return (grand_p->left != parent ? grand_p->left : grand_p->right);

	return (NULL);
}
