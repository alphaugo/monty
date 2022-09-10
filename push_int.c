#include "monty.h"
/**
 * push - function
 * @stack: stack memo
 *
 * @line: --
 */
void push(stack_t **stack, unsigned int line)
{
	(void) line;

	temp = malloc(sizeof(stack_t));

	if(!temp)
	{
		fprintf(stderr, "Error: malloc allocation faild\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (temp)
	{
		temp->next = NULL;
		temp->prev = NULL;
	}

	if (!(stack))
		(*stack) = temp;
	else
	{
		(*stack)->prev = temp;
		temp->next = *stack;
		*stack = temp;
	}

	free(temp);
	temp = NULL;
}
