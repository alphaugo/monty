#include "monty.h"
/**
 * validator - function that checks if the second value of token is valid
 * @token: the token
 * @stack: out stack store.
 *
 * Return: nothing
 */
void validator(char **token, stack_t **stack)
{
	int index = 0;

	if (!token[1])
	{
		fprintf(stderr, "L%u: usage: push interger\n", line_number);
		if (*stack)
			free_stack(stack);
		free(token);
		exit(EXIT_FAILURE);
	}
	while (token[1][index])
	{
		if (token[1][index] == '_' && index == 0)
			index++;
		if (isdigit(token[1][index]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			if (*stack)
				free_stack(stack);
			free(token);
			exit(EXIT_FAILURE);
		}
		index++;
	}
}
