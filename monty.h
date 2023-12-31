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
 * @lineptr: line read
 * @token: argument
 * @op_code: op code
 * @fptr: file pointer
 * @num: integer
 * @mode: mode selector
 */
typedef struct global_variables
{
char *lineptr;
char *token;
char *op_code;
FILE *fptr;
int num;
int mode;
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

void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void error(stack_t **stack, unsigned int n);
void parse_to_int(stack_t **stack, unsigned int n);
void swap(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int line_number);
void (*func(char *tokens))(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void handle_error(stack_t **stack);
#endif

