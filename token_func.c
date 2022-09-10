#include "monty.h"
/**
 * persser_t - function that returns a ponter
 * @buffer: points to where the bytecode command is
 *
 * Return: a pinter to a pointer
 */

char **persser_t(char *buffer)
{
	/* token takes in the tokenized command in buffer*/
	char *token = NULL;
	/* arranged takes in what is inside token in an arranged form */
	char **arranged_token;
	/* delem sets the arrangement of the argument */
	char *delem = "\t  \r\n";
	int index = 3;

	token = strtok(buffer, delem);

	if (token == NULL)
		return (NULL);

	arranged_token = malloc(sizeof(char **) * 3);
	if (arranged_token == NULL)
	{
		fprintf(stderr, "Error: Malloc Failed");
		exit(EXIT_FAILURE);
	}
	while (--index)
	{
		arranged_token[index - 1] = NULL;
	}

	while (token)
	{
		if (index < 3)
			arranged_token[index] = token;
		token = strtok(NULL, delem);

		index++;
	}

	arranged_token[2] = NULL;

	return (arranged_token);
}
