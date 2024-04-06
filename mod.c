#include "monty.h"

/**
 * _mod -  modulus of second top element with the top.
 * @queues: pointer to the stack
 * @line_number: line number of the opcode
 */
void _mod(stack_t **queues, unsigned int line_number)
{
	int i, j;

	if (*queues == NULL || (*queues)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to open, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*queues)->h;
	j = (*queues)->next->h;

	if (i == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*queues)->next->h = j % i;
	pop_opcode(queues, line_number);
}
