#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent node for created node
 * @value: value fo created node
 * Return: pointer to the new node
 *         NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = node->right = NULL;

	return (node);
}
