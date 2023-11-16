#include "monty.h"

/**
 * func - pointers to functions
 * @tokens: arguments
 * Return: function
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_line)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"#", nop},
		{"pint", pint},
		{"err", error},
		{NULL, NULL}
	};
	int i = 0;
	int array_len = sizeof(funcs) / sizeof(funcs[0]);

	/*printf("array: %d\n", array_len);*/
	while (i < array_len)
	{
		if (strcmp(funcs[i].opcode, tokens) == 0)
			return (funcs[i].f);
		i++;
	}
	return (funcs[array_len - 2].f);
}

