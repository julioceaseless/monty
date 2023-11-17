#include "monty.h"
/**
 * free_stack - free the stack (linked list)
 * @head: head pointer
 */
void free_stack(stack_t **head)
{
	if (*head)
	{
		free_stack(&((*head)->next));
		free(*head);
		*head = NULL;
	}
}
