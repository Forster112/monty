#include "monty.h"

/**
 * add - function that adds the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @ln: error line number
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int ln)
{
	int a, b, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;

	pop(stack, ln);

	(*stack)->n = sum;
}

/**
 * sub - substracts element of a stack
 * @stack: pointer to the top of stack
 * @ln: error line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int ln)
{
	int a, b, diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	diff = b - a;

	pop(stack, ln);

	(*stack)->n = diff;
}

/**
 * do_div - divides elements of a stack
 * @stack: pointer to top of stack
 * @ln: error line number
 * Return: nothing
 */
void do_div(stack_t **stack, unsigned int ln)
{
	int a, b, divide;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	divide = b / a;

	pop(stack, ln);
	(*stack)->n = divide;
}

/**
 * _mul - multiplies elements of a stack
 * @stack: pointer to top stack
 * @ln: error line number
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int ln)
{
	int a, b, times;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	times = b * a;
	pop(stack, ln);

	(*stack)->n = times;
}

/**
 * _mod - retrives the remainder of a division
 * @stack: pointer to top stack
 * @ln: error line number
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int ln)
{
	int a, b, modulo;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	modulo = b % a;
	pop(stack, ln);
	(*stack)->n = modulo;
}
