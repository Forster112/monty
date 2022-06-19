#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @ln: line number
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int ln)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (!(num >= 0 && num <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @UNUSED: line number
 * Return: nothing
 */
void _pstr(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *h;
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	h = *stack;
	while (h != NULL)
	{
		num = h->n;
		if (num == 0 || !(num >= 0 && num <= 127))
			break;

		printf("%c", num);
		h = h->next;
	}
	printf("\n");
}

/**
 * _rotl - function that rotates the stack to the top
 * @stack: pointer to the stack
 * @ln: line number
 * Return: nothing
 */


void _rotl(stack_t **stack, unsigned int ln)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, ln);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	tail->next = head;
	head->next = NULL;
	head->prev = tail;
}

/**
 * _rotr - function that rotates the stack to the top
 * @stack: pointer to the stack
 * @ln: line number
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int ln)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, ln);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head = tail;
	*stack = head;
}
