#include "monty.h"

/**
 * error - manage errors
 * @stack: head
 * @n: integer
 */
void error(stack_t **stack, unsigned int n)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", n, global.lineptr);
	free(global.lineptr);
	fclose(global.fptr);
	free_stack(stack);
	if (stack)
	{
	}
	exit(EXIT_FAILURE);
}

