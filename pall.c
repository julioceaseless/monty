#include "monty.h"

/**
 * pall - prints all the values in the stack from top to bottom
 * @stack: head pointer of the stack
 * @line_num: line number of the bytecode
 * Return: nothing!
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	temp = *stack;
	if (line_num)
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
