#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure height
 * Return: height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check
 * Return: 1 if perfect 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height_l = binary_tree_height(tree->left);
	size_t height_r = binary_tree_height(tree->right);
	int perf;

	if (!tree || height_l != height_r)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	perf = binary_tree_is_perfect(tree->left);
	perf &= binary_tree_is_perfect(tree->right);

	return (perf);
}
