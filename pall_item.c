#include "monty.h"
/**
 * pall_item - To print all values on the stack
 * @queues: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void pall_item(stack_t **queues, unsigned int line_number)
{
stack_t *current = *queues;
while (current != NULL)
{
printf("%d\n", current->h);
current = current->next;
(void)line_number;
}
}
