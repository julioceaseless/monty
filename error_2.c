#include "monty.h"
/**
 * handle_error - generic error handler
 * @stack: head pointer to the node
 *
 */
void handle_error(stack_t **stack)
{
	free(global.lineptr);
	fclose(global.fptr);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
