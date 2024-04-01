#include "monty.h"
/*global struct declared*/
glob_s glob;

/**
 * main - The Main function for monty program.
 * @argc: arguments count
 * @argv: argument vector
 *
 * Return: 0 on success, non-zero on failure
 */

int main(int argc, char *argv[])
{
/*empty double linked list*/
stack_t *queues = NULL;
/*main take in two argument if not 2 do this*/
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
/*else argv[1] is a file open it*/
glob.fpter = fopen(argv[1], "r");
if (glob.fpter == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
process_file(&queues);
fclose(glob.fpter);
free(glob.line);
free_list(queues);
exit(EXIT_SUCCESS);
}
