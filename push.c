#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: head pointer of the stack
 * @line_number: line number of opcode
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL, *temp = NULL;

	parse_to_int(head, line_number);
	if (global.token)
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		newnode->n = global.num, newnode->next = NULL;
		newnode->prev = NULL;
		if (*head != NULL)
		{
			temp = *head;
			if (global.mode == 1)
			{
				newnode->next = *head;
				(*head)->prev = newnode, *head = newnode;
			}
			else
			{
				while (temp->next != NULL) /* navigate to last node */
					temp = temp->next;
				temp->next = newnode;
				newnode->prev = temp;
			}
		}
		else
			*head = newnode; /* when stack is empty */
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		handle_error(head);
	}
}
