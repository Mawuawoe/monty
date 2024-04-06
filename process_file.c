#include "monty.h"
/**
 * process_file - reads and executes opcodes from a file
 * @queues:The pointer to the top of the stack
 */

void process_file(stack_t **queues)
{
char *opcode = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 0;
while ((read = getline(&glob.line, &len, glob.fpter)) != -1)
{
line_number++;
opcode = strtok(glob.line, " \t\n");
glob.arg = strtok(NULL, " \t\n");
if (opcode == NULL || *opcode == '#')
continue;
exec_opcode(opcode, queues, line_number);
}
}

/**
 * exec_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @queues: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void exec_opcode(char *opcode, stack_t **queues, unsigned int line_number)
{
instruction_t instruction[] = {
{"push", push_item},
{"pall", pall_item},
{"pint", peek},
{"pop", pop},
{"swap", swap_top},
{"add", add},
{"nop", do_nothing},
{"sub", sub},
{"div", _div},
{"mul", _mul},
{"mod", _mod},
{NULL, NULL}
};

int i;
int a;
for (i = 0; instruction[i].opcode != NULL; i++)
{
a = strcmp(opcode, instruction[i].opcode);
if (a == 0)
{
instruction[i].f(queues, line_number);
return;
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free_list(*queues);
fclose(glob.fpter);
free(glob.line);
exit(EXIT_FAILURE);
}
