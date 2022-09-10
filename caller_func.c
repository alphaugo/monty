#include "monty.h"
static instruction_t lux[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * call_func - function
 * @token: has the momory address of arranged_func
 * @stack: has the memory address of the right func to be called
 *
 * Return: void
 */

void call_func(char **token, stack_t **stack)
{
	int index = 0;
	unsigned int len = line_number;

	while (lux[index].opcode)
	{
		if (token[0][0] == '#')
			return;
		if (strcmp(token[0], lux[index].opcode) == 0)
		{
			if (lux[index].f)
				lux[index].f(stack, len);
			break;
		}
		index++;
	}

	if (strcmp(token[0], "push") == 0)
	{
		validator(token, stack);
		(*stack)->n = atoi(token[1]);
	}
	else if (!(lux[index].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				token[0]);
		exit(EXIT_FAILURE);
	}
}
