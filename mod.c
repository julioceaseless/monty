#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: head pointer
 * @line_number: number of line
 */
void _mod(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->next->n % (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
