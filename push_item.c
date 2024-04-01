#include "monty.h"

/**
 * is_integer - checks if a string is an integer
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_integer(char *str)
{
if (str == NULL || *str == '\0')
return (0);
if (*str == '-' || *str == '+')
str++;
while (*str != '\0')
{
if (*str < '0' || *str > '9')
return (0);
str++;
}
return (1);
}
/**
 * push_item - pushes an element onto the stack
 * @queues: pointer to top of the stack
 * @line_number: The line number of the opcode
 */
void push_item(stack_t **queues, unsigned int line_number)
{
int data;
if (glob.arg == NULL || !is_integer(glob.arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_list(*queues);
fclose(glob.fpter);
free(glob.line);
exit(EXIT_FAILURE);
}
data = atoi(glob.arg);
if (add_node(queues, data) == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_list(*queues);
fclose(glob.fpter);
free(glob.line);
exit(EXIT_FAILURE);
}
}
