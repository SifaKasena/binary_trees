#include "binary_trees.h"

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

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	
	return (sort_insertion_helper(array, NULL, 0, size - 1));
}