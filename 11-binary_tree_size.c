#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Tree to get size of
 * Return: size of tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = tree->left ? 1 + binary_tree_size(tree->left) : 1;
	size = tree->right ? size + binary_tree_size(tree->right) : size;

	return (size);
}
