#include "monty.h"
/**
 * pstr - prints the string starting at the top of
 * the stack, followed by a new line
 * @head: head pointer
 * @line_num: line number
 */

void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;

	(void)line_num;
	/**
	if (*head == NULL)
	{
		free(global.lineptr);
		fclose(global.fptr);
		free_stack(head);
		dprintf(STDERR_FILENO, "L%u: can't pstr, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	**/
	temp = *head;
	while (temp != NULL && temp->n != 0 && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

