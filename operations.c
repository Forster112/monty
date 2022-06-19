#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of stack
 * @ln: error line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int ln)
{
	stack_t *top;
	char *str_num;
	int nm;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "error allocating memory");
		exit(EXIT_FAILURE);
	}
	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || _isdigit(str_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		free(top);
		exit(EXIT_FAILURE);
	}
	nm = atoi(str_num);
	top->n = nm;
	top->prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		*stack = top;
		top->next = NULL;
		return;
	}
	top->next = (*stack);
	(*stack)->prev = top;
	*stack = top;
}

/**
 * pall - function that prints all the values in the stack
 * @stack: pointer to the top of the stack
 * @ln: not used
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int ln)
{
	stack_t *head;
	(void)ln;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * pint - function that prints the first element of the stack
 * @stack: pointer to the top of the stack
 * @ln: error line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop - function that removes the first element of the stack
 * @stack: pointer to the top of the stack
 * @ln: error line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = NULL;

	free(temp);
}

/**
 * swap - function that swaps the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @ln: error line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int ln)
{
	int temp1, temp2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;

	(*stack)->n = temp2;
	(*stack)->next->n = temp1;
}
