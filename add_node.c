#include "monty.h"

/**
 * add_node - To adds a new node at the beginning of a stack_t list
 * @queues: pointer to pointer to linked list
 * @data: value to be added to the new node
 *
 * Return: pointer to the newly added node
 */
stack_t *add_node(stack_t **queues, const int data)
{
stack_t *newNode;
newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
{
fprintf(stderr, "Error: Usage failed\n");
exit(EXIT_FAILURE);
}
newNode->prev = NULL;
newNode->h = data;
newNode->next = NULL;
if (*queues == NULL)
{
*queues = newNode;
}
else
{
newNode->next = *queues;
(*queues)->prev = newNode;
*queues = newNode;
}
return (newNode);
}
