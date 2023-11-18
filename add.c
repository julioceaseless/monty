#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: head pointer
 * @line_number: number of line
 */
void _add(stack_t **head, unsigned int line_number)
{
	int sum = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free((*head)->prev);
	(*head)->n = sum;
}
