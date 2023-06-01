#include "binary_trees.h"
void pint_push(binary_tree_t *node, levelorder_queue_t *front,
		levelorder_queue_t **rear);
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
 * push - pushes a node to the back of a levelorder_queue_t queue.
 * @node: pointer to binary tree node to print and push.
 * @front: double pointer to the head of the queue.
 * @rear: double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *front,
		levelorder_queue_t **rear)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (!new_node)
	{
		free_queue(front);
		exit(1);
	}
	(*rear)->next = new_node;
	*rear = new_node;
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
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *front, *rear;
	unsigned char flag = 0;

	if (!tree)
		return (0);

	front = rear = create_node((binary_tree_t *)tree);
	if (!front)
		exit(1);

	while (front != NULL)
	{
		if (front->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(front);
				return (0);
			}
			pint_push(front->node->left, front, &rear);
		}
		else
			flag = 1;
		if (front->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(front);
				return (0);
			}
			pint_push(front->node->right, front, &rear);
		}
		else
			flag = 1;
		pop(&front);
	}
	return (1);
}
