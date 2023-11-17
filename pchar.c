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
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

