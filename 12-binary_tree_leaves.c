#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree to count leaves
 * Return: Number of leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves;

	if (!tree)
		return (0);

	leaves = (tree->left || tree->right) ? binary_tree_leaves(tree->left) : 1;
	leaves = leaves + binary_tree_leaves(tree->right);

	return (leaves);
}
