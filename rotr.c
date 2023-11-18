#include "monty.h"
/**
 * rotr - rotates the stack to the top
 * @head: head pointer
 * @line_num: dummy
 */
void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;

	(void)line_num;
	if (*head && (*head)->next)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		/* move head to the last node */
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
