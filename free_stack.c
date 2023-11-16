#include "monty.h"
/**
 * free_stack - free the stack (linked list)
 * @head: head pointer
 */
void free_stack(stack_t **head)
{
	stack_t *temp = NULL;

	temp = *head;

	while (*head)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
}
