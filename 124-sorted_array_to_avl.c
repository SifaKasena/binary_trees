#include "binary_trees.h"

/**
 * sort_insertion_helper - Recursively inserts elements into an avl tree
 * @array: Array of elements to insert
 * @parent: parent of element to insert
 * @start: index of the beggining of array
 * @end: last index of array
 * Return: pointer to the created tree
*/
avl_t *sort_insertion_helper(int *array, avl_t *parent, int start, int end)
{
	avl_t *tree;
	int mid;

	if (start <= end)
	{
		mid = (start + end) / 2;
		tree = binary_tree_node(parent, array[mid]);
		if (!tree)
			return (NULL);
		tree->left = sort_insertion_helper(array, tree, start, mid - 1);
		tree->right = sort_insertion_helper(array, tree, mid + 1, end);
		return (tree);
	}

	return (NULL);
}


/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Array to create avl tree from
 * @size: size of array
 * Return: pointer to th root of the avl tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);

	return (sort_insertion_helper(array, NULL, 0, size - 1));
}
