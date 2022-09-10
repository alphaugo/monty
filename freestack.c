#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: ptr to stack
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *head = *stack;

	while (head)
	{
		if (!head->next)
		{
			free(head);
			break;
		}
		head = head->next;
		free(head->prev);
	}
}
