#include "monty.h"
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: head
 * @line_num: line number
 */

void queue(stack_t **stack, unsigned int line_num)
{
	if (stack || line_num)
		global.mode = 0;
}

