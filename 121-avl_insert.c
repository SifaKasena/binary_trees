#include "binary_trees.h"

/**
 * _balance - balances avl tree after insertion
 * @tree: tree to balance
 * @value: value of inserted node
 * Return: void
*/
void _balance(avl_t *tree, int value)
{
	int balance;

	balance = binary_tree_balance(tree);
	if (tree->left && > 1 &&  value < tree->left->n)
		binary_tree_rotate_right(tree);
	if (tree->left && balance > 1 && value > tree->left->n)
	{
		binary_tree_rotate_left(tree->left);
		binary_tree_rotate_right(tree);
	}
	if (tree->right && balance < -1 && value > tree->right->n)
		binary_tree_rotate_left(tree);
	if (tree->right && balance < -1 && value < tree->right->n)
	{
		binary_tree_rotate_right(tree->right);
		binary_tree_rotate_left(tree);
	}
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to insert
 * Return: address of inserted node
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *parent;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = *tree;
	if (value < parent->n)
	{
		if (parent->left)
			node = avl_insert(&(parent->left), value);
		else
		{
			node = binary_tree_node(parent, value);
			parent->left = node;
		}
	}
	else if (value > parent->n)
	{
		if (parent->right)
			node = avl_insert(&(parent->right), value);
		else
		{
			node = binary_tree_node(parent, value);
			parent->right = node;
		}
	}
	else
		return (parent);

	_balance(parent, value);

	return (node);
}
