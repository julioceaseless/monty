#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @head: head pointer to the stack
 * @line_num: line number of the opcode
 * Return: Nothing!
 */
void pint(stack_t **head, unsigned int line_num)
{
	if ((*head))
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
}
