#include "monty.h"
/**
 * _sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @head: head pointer
 * @line_number: number of line
 */
void _sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->next->n - (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
