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
	int line_num = 1;
	ssize_t read_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = argv[1];
	if (!check_File_access(file_path, R_OK))
	{
		fprintf(stderr, "Error: Can't read file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(file_path, "r");
	while ((read_line = getline(&line, &line_buffer_size, file)) != -1)
	{
		line_num++;
		line[strcspn(line, "\n")] = '\0';
		process_command(line, line_num);
	}
	free(line);
	fclose(file);
	return (0);
}
