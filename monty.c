#include "monty.h"

/**
 * main - This is a program that implements a monty bytecode intepreter.
 * @argc: integer count of instractionsa passed to the interpreter.
 * @argv: arguments passed to the interpreter.
 * Return: 0 On success.
 */

int main(int argc, char *argv[])
{
	const char *file_path;
	FILE *file;
	char *line = NULL;
	size_t line_buffer_size = 0;
	unsigned int line_num = 1;
	ssize_t read_line;
	stack_t *stack;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = argv[1];
	if (access(file_path, F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't read file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(file_path, "r");
	while ((read_line = getline(&line, &line_buffer_size, file)) != -1)
	{
		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		process_command(line, &stack, line_num);
		line_num++;
	}
	free(line);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	fclose(file);
	return (0);
}
