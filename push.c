#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: head pointer of the stack
 * @line_number: line number of opcode
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL;

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
			if (global.flag == 1)
			{
				newnode->next = *head;
				(*head)->prev = newnode, *head = newnode;
			}
			else
			{
				while ((*head)->next)
					*head = (*head)->next;
				(*head)->next = newnode, newnode->prev = *head;
				while ((*head)->prev)
					*head = (*head)->prev;
			}
		}
		else
			*head = newnode;
	}
	else
	{
		free(global.lineptr);
		fclose(global.fptr);
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
