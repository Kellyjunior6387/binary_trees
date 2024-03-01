#include "binary_trees.h"
/**
 * struct queue_node_s - A node for a queue dsa
 * @node: a binary tree to be traversed
 * @next: pointer to next node
 */
struct queue_node_s
{
	binary_tree_t *node;
	struct queue_node_s *next;
};
typedef struct queue_node_s queue_node_t;
/**
 * struct queue_s - an implementation for a queue
 * @front: Pointer to front of the queue
 * @rear: Pointer to rear of the queue
 */
struct queue_s
{
	queue_node_t *front;
	queue_node_t *rear;
};
typedef struct queue_s queue_t;
/**
 * create_queue - Function to create an empty queue
 * Return: The newly created queue
 */
queue_t *create_queue()
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}
/**
 * is_empty - Function to check if queue is empty
 * @queue: queue to be checked
 * Return: 1 if empty otherwise NULL
 */
int is_empty(queue_t *queue)
{
	if (queue->front == NULL)
		return (1);
	return (0);
}
/**
 * push - Function to enqueue a node
 * @queue: The queue whose a node is to be added
 * @node: node to be added
 */
void push(queue_t **queue, binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (!new_node)
		return;
	new_node->node = node;
	new_node->next = NULL;

	if ((*queue)->rear == NULL)
	{
		(*queue)->front = new_node;
		(*queue)->rear = new_node;
	}
	else
	{
		(*queue)->rear->next = new_node;
		(*queue)->rear = new_node;
	}
}
/**
 * pop - Function to dequeue a queue
 * @queue: The queue whose a node is to be removed
 */
binary_tree_t *pop(queue_t **queue)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (is_empty(*queue))
		return (NULL);
	temp = (*queue)->front;
	node = temp->node;
	(*queue)->front = (*queue)->front->next;
	if ((*queue)->front == NULL)
		(*queue)->rear = NULL;
	free(temp);
	return node;
}
/**
 * free - Function to free a queue
 * @queue: Queue to be freed
 */
void free_queue(queue_t *queue)
{
	while (!is_empty(queue))
	{
		pop(&queue);
	}
	free(queue);
}

/**
 * binary_tree_levelorder - Function to go through a binary tree
 * @tree: pointer to the root node
 * @func: Function to be called for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue();
	push(&queue,(void *) tree);

	while(!is_empty(queue))
	{
		current = (binary_tree_t *)pop(&queue);
		func(current->n);

		if (current->left != NULL)
			push(&queue, (void *)current->left);
		if (current->right != NULL)
			push(&queue, (void *)current->right);
	}
	free_queue(queue);
}
