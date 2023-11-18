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
		{"pop", _pop},
		{"add", _add},
		{"sub", _sub},
		{"mod", _mod},
		{"div", _div},
		{"mul", _mul},
		{"swap", swap},
		{"pint", pint},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"#", nop},
		{"err", error},
		{NULL, NULL}
	};
	int i = 0, check_func;
	int len = (sizeof(funcs) / sizeof(funcs[0]) - 1);

	/*printf("array: %d\n", array_len);*/
	while (i < len)
	{

		check_func = strcmp(funcs[i].opcode, tokens);
		if (check_func == 0)
			return (funcs[i].f);
		i++;
	}
	return (funcs[len - 1].f);
}

