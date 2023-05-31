#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}

/**
 * _balance - balances avl tree after insertion
 * @tree: tree to balance
 * @value: value of inserted node
 * Return: void
*/
void _balance(avl_t *tree, int value)
{
	int balance;

	if (!tree)
		return;

	balance = binary_tree_balance(tree);
	if (tree->left && balance > 1 && value < tree->left->n)
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

	_balance(tree->left, value);
	_balance(tree->right, value);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to insert
 * Return: address of inserted node
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;
	/**
	 * avl_t *node, *parent;
	 *
	 * if (!(*tree))
	 * {
	 * *tree = binary_tree_node(NULL, value);
	 * return (*tree);
	 * }
	 *
	 *      parent = *tree;
	 * if (value < parent->n)
	 * {
	 *      if (parent->left)
	 *              node = avl_insert(&(parent->left), value);
	 *      else
	 *      {
	 *              node = binary_tree_node(parent, value);
	 *		parent->left = node;
	 *	}
	 * }
	 * else if (value > parent->n)
	 * {
	 *	if (parent->right)
	 *		node = avl_insert(&(parent->right), value);
	 *	else
	 *	{
	 *		node = binary_tree_node(parent, value);
	 *		parent->right = node;
	 *	}
	 * }
	 * else
	 *	return (parent);
	*/

	node = bst_insert(tree, value);

	_balance(*tree, value);

	return (node);
}
