#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * main - main function
 * @argc: argument counter
 * @argv: argument variable list
 *
 * Return: nothing
 */
int main(int argc, char *argv[])
{
	char **token = NULL;
	stack_t *head = NULL;
	char *buffer = NULL;
	FILE *fp;
	size_t n;
	int monty;

	if (argc != 2)
	{
		fprintf(stderr, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty = getline(&buffer, &n, fp);

	while (monty != -1)
	{
		line_number++;
		token = persser_t(buffer);
		if (token)
		{
			call_func(token, &head);
			free(token);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);
	return (0);
}
