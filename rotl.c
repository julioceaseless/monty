#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: head pointer
 * @line_num: dummy
 */
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *templ = NULL;
	stack_t *temp = NULL;

	(void)line_num;
	if (*head && (*head)->next)
	{
		templ = temp = *head;
		while (temp->next)
			temp = temp->next;
	/* move head to the second node */
		*head = (*head)->next;
		(*head)->prev = NULL;
		temp->next = templ;
		templ->prev = temp;
		templ->next = NULL;
	}
}
