#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_par, *sec_par;

	if (!first || !second)
		return(NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	first_par = first->parent;
	sec_par = second->parent;
	if (first == sec_par || !first_par || (!first_par->parent && sec_par))
		return (binary_trees_ancestor(first, sec_par));
	else if (first_par == second || !sec_par || (!sec_par->parent && first_par))
		return (binary_trees_ancestor(first_par, second));
	return (binary_trees_ancestor(first_par, sec_par));
}
