#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old_right_node;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	old_right_node = parent->right;
	parent->right = new;

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = old_right_node;

	if (old_right_node != NULL)
	{
		old_right_node->parent = new;
	}

	return (new);
}
