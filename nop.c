#include "monty.h"

/**
 * d_stack - opcode that does nothing
 * @stack: pointer to stack
 * @ln: line number
 * Return: nothing
 */
void d_stack(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
	bus.lifi = 0;
}

/**
 * d_queue - opcode
 * @stack: pointer to stack
 * @ln: line number
 * Return: nothing
 */
void d_queue(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
	bus.lifi = 1;
}
