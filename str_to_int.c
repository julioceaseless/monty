#include "monty.h"
/**
 * parse_to_int - converts string number to int. Throws error otherwise.
 * @stack: head pointer of stack
 * @line_num: line number of the bytecode
 * Return: nothing!
 */
void parse_to_int(stack_t **stack, unsigned int line_num)
{
	int index = 0;

	if (global.token == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		free(global.lineptr);
		fclose(global.fptr);
		exit(EXIT_FAILURE);
	}
	/* check negative */
	if (global.token[index] == '-')
		index++;
	while (global.token[index])
	{
		if (!(global.token[index] >= '0' && global.token[index] <= '9'))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
			free_stack(stack);
			free(global.lineptr);
			fclose(global.fptr);
			exit(EXIT_FAILURE);
		}
		index++;
	}
	global.num = atoi(global.token);
}

