#include "binary_trees.h"
/**
 * create_node - creates a new node.
 * @node: pointer to the new binary tree node
 *
 * Return: pointer to the new node or NULL on error
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}
/**
 * push - pushes its children into a levelorder_queue_t queue.
 * @node: pointer to binary tree node to print and push.
 * @front: double pointer to the head of the queue.
 * @rear: double pointer to the tail of the queue.
 * @func: pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *front,
		levelorder_queue_t **rear, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = create_node(node->left);
		if (new_node == NULL)
		{
			free_queue(front);
			exit(1);
		}
		(*rear)->next = new_node;
		*rear = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_node(node->right);
		if (new_node == NULL)
		{
			free_queue(front);
			exit(1);
		}
		(*rear)->next = new_node;
		*rear = new_node;
	}
}
/**
 * pop - pops the head of a levelorder_queue_t queue.
 * @front: double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **front)
{
	levelorder_queue_t *temp;

	temp = (*front)->next;
	free(*front);
	*front = temp;
}
/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *front, *rear;

	if (!tree || !func)
		return;

	front = rear = create_node((binary_tree_t *)tree);
	if (!front)
		return;

	while (!front)
	{
		push(front->node, front, &rear, func);
		pop(&front);
	}
}
/**
 * free_queue - frees a levelorder_queue_t queue.
 * @front: pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *front)
{
	levelorder_queue_t *temp;

	while (!front)
	{
		temp = front->next;
		free(front);
		front = temp;
	}
}
