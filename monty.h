#ifndef MAIN_H
#define MAIN_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct global - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @fpter: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global
{
char *arg;
FILE *fpter;
char *line;
} glob_s;

extern glob_s glob;

/**
 * struct queues_s - doubly linked list representation of a stack (or queue)
 * @h: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct queues_s
{
int h;
struct queues_s *prev;
struct queues_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_item(stack_t **queues, unsigned int line_number);
void free_list(stack_t *queues);
void process_file(stack_t **queues);
void pall_item(stack_t **queues, unsigned int line_number);
void exec_opcode(char *opcode, stack_t **queues, unsigned int line_number);
int is_integer(char *str);
stack_t *add_node(stack_t **queues, const int data);
void peek(stack_t **queues, unsigned int line_number);
void pop(stack_t **queues, unsigned int line_number);
void swap_top(stack_t **queues, unsigned int line_number);
void add(stack_t **queues, unsigned int line_number);
void do_nothing(stack_t **queues, unsigned int line_number);
void sub(stack_t **queues, unsigned int line_number);
void _div(stack_t **queues, unsigned int line_number);




#endif
