#include "monty.h"

/**
 * func - pointers to functions
 * @tokens: arguments
 * Return: function
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_line)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"#", nop},
		{"pint", pint},
		{"err", error},
		{NULL, NULL}
	};
	int i = 0;
	int opc;
	size_t ops_len = sizeof(ops) / sizeof(ops[0]);

	while (i < ops_len)
	{
		opc = strcmp(ops[i].opcode, tokens);
		if (opc == 0)
			return (ops[i].f);
		i++;
	}

	return (ops[ops_len - 2].f);
}

