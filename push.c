#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: head pointer of the stack
 * @line_number: line number of opcode
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;

	parse_to_int(stack, line_number);
	if (global.token)
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		newnode->n = global.num, newnode->next = NULL, newnode->prev = NULL;
		if (*stack)
		{
			if (global.flag == 1)
			{
				newnode->next = *stack;
				(*stack)->prev = newnode;
				*stack = newnode;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = newnode, newnode->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = newnode;
	}
	else
	{
		free(global.lineptr);
		fclose(global.fptr);
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
