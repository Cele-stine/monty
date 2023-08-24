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
	char *opcode;
	size_t i;
	int found_opcode = 0;
	size_t num_opcodes;
	char *arg_str;
	int value;

	instruction_t opcodes[] = {
		{"PUSH", push_function}
	};

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(command_copy, " ");
	if (opcode == NULL)
	{
		fprintf(stderr, "L<(%d)>: unknown instruction <(%s)>\n", line_num, command);
		exit(EXIT_FAILURE);
		free(command_copy);
	}
	num_opcodes = sizeof(opcodes) / sizeof(opcodes[0]);
	for (i = 0; i < num_opcodes; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			found_opcode = 1;
			if (strcmp(opcode, "PUSH") == 0)
			{
				arg_str = strtok(NULL, " ");
				if (arg_str == NULL)
				{
					free(command_copy);
					exit(EXIT_FAILURE);
				}
				value = atoi(arg_str);
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
		fprintf(stderr, "L<(%u)>: unknown instruction <(%s)>\n", line_num, opcode);
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	free(command_copy);
}
