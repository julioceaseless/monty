#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: head pointer
 * @line_number: line number
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->next = temp->next;
	(*head)->prev = temp;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}


