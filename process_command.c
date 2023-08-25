#include "monty.h"
#include <stdlib.h>

/**
 * process_command - a function that processes instractions passed to the
 * interpretor from a monty file.
 * @command: the instraction passed.
 * @line_num: Number assigned to the instraction line in the monty file.
 * Return: Nothing.
 */

void process_command(const char *command, stack_t **stack, unsigned int line_num)
{
	char *command_copy;
	char *opcod;
	size_t i;
	int found_opcode = 0;
	size_t num_opcodes;
	int value;
	char *arg;

	instruction_t opcodes[] = {
		{"push", push_function},
		{"pall", pall_function},
	};

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcod = strtok(command_copy, " \n\t");
	if (opcod == NULL)
	{
		fprintf(stderr, "L<(%d)>: unknown instruction <(%s)>\n", line_num, command);
		exit(EXIT_FAILURE);
		free(command_copy);
	}
	num_opcodes = sizeof(opcodes) / sizeof(opcodes[0]);
	for (i = 0; i < num_opcodes; i++)
	{
		if (strcmp(opcod, opcodes[i].opcode) == 0)
		{
			found_opcode = 1;
			if (strcmp(opcod, "push") == 0)
			{
				arg = strtok(NULL, " \n\t");
				if (arg == NULL)
				{
					free(command_copy);
					exit(EXIT_FAILURE);
				}
				value = atoi(arg);
				opcodes[i].f(stack, value);
			}
			else
			{
				opcodes[i].f(stack, line_num);
			}
			break;
		}
	}
	if (!found_opcode)
	{
		fprintf(stderr, "L<(%u)>: unknown instruction <(%s)>\n", line_num, opcod);
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	free(command_copy);
}
