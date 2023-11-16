#ifndef MONTY_H_
#define MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * struct global_variables - these are shared variables
 * @line: string
 * @token: string
 * @op_code: string
 * @fptr: file pointer
 * @num: integer
 * @flag: integer
 */
typedef struct global_variables
{
char *lineptr;
char *token;
char *op_code;
FILE *fptr;
int num;
int flag;
} global_vars;

extern global_vars global;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
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

void mod(stack_t **stack, unsigned int num_line);
void stack(stack_t **stack, unsigned int num_line);
void error(stack_t **stack, unsigned int n);
void parse_to_int(stack_t **stack, unsigned int n);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int num_line);
void (*func(char *tokens))(stack_t **stack, unsigned int num_line);
void pall(stack_t **stack, unsigned int num_line);
void push(stack_t **stack, unsigned int num_line);
void pint(stack_t **head, unsigned int line_num);
#endif

