#include "binary_trees.h"

/**
 * array_to_avl - Creates an avl tree from an array
 * @array: Array to create avl tree from
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created avl, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		if (avl_insert(&tree, array[i]) == NULL)
			return (NULL);

	return (tree);
}
