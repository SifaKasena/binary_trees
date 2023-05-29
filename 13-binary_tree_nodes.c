#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree to count nodes
 * Return: Number of nodes with at least 1 child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes;

	if (!tree)
		return (0);

	nodes = (tree->left || tree->right) ? 1 + binary_tree_nodes(tree->left) : 0;
	if (tree->left || tree->right)
		nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
