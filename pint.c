#include "monty.h"
#include <stdio.h>
/**
 * pint - prints the value at the top of the stack
 * @head: head pointer to the stack
 * @line_number: line number of the opcode
 * Return: Nothing!
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
