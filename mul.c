#include "monty.h"
/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @head: head pointer
 * @line_number: number of line
 */
void _mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->n * (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
