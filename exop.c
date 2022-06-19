#include "monty.h"

/**
 * exe_operation - function that executes opcodes
 * @op_command: opcode commamd
 * @head: pointer to head
 * @ln: line number
 * Return: nothing
 */
void exe_operation(char *op_command, stack_t **head, unsigned int ln)
{
	int i;
	instruction_t all_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", do_div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op_command, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(head, line_number);
			return;
		}
	}

	if (op_command[0] != '#' && strlen(op_command) != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", ln, op_command);
		free_fp_line();
		exit(EXIT_FAILURE);
	}
}
