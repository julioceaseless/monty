#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: head pointer
 * @line_number: line number
 */
void _pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
		free_stack(head);
}

