#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @head: head pointer
 * @line_num: line number
 */

void pchar(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_num);
		handle_error(head);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_num);
		handle_error(head);
	}
	printf("%c\n", (*head)->n);
}

