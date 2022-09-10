#include "monty.h"
/**
 * pall - function
 * @stack: stack
 * @line: --
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line)
{
	(void) line;

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc allocation failed\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
	temp = NULL;
}
