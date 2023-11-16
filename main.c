#include "monty.h"
/**
 * trim_line - remove line
 * @line: line
 * Return: nothing!
 */
void trim_line(char *line)
{
	size_t len = 0;

	for (; line[len] != '\0'; len++)
		;
	line[len - 1] = '\0';
}
/**
 * main - main entry
 * @argc: count of command line arguments
 * @argv: command line arguments
 * Return: 0 always!
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	size_t size_n = 0, bytes_read = 0;
	unsigned int line_num = 1;

	global.flag = 1;
	global.lineptr = NULL;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fptr = fopen(argv[1], "r");
	if (global.fptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = getline(&global.lineptr, &size_n, global.fptr)) != EOF)
	{
		trim_line(global.lineptr);
		if (global.lineptr[0] != '#')
		{
			global.token = strtok(global.lineptr, " \t\n");
			global.op_code = global.token;
			if (global.op_code != NULL)
			{
				global.token = strtok(NULL, " \t\n");
				func(global.op_code)(&head, line_num);
				printf("%u:%s\n", line_num, global.op_code);
			}
			line_num++;
		}
		else
			line_num++;
	}
	free_stack(&head);
	free(global.lineptr);
	fclose(global.fptr);
	return (0);
}
