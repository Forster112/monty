#include "monty.h"

/**
 * free_dataStructure - function that frees a data structure
 * Return: nothing
 */
void free_dataStructure(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(glob_var.top);

	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}

/**
 * free_fp_line - function that frees the file pointer and line
 * Return: nothing
 */
void free_fp_line(void)
{
	fclose(glob_var.fp);

	if (glob_var.line)
		free(glob_var.line);
}
