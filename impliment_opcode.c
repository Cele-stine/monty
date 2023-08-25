#include "monty.h"

/**
 * push_function - a function that pushes an element into the stack.
 * @*stack: the stack to push the element to.
 * @line_number: the element to push
 * Return: void
 */

void push_function(stack_t **stack, unsigned int value)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", value);
			fclose(bus.file);
			free(bus.content);
			free(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", value);
		fclose(bus.file);
		free(bus.content);
		free(*stack);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}

/**
 * pall_fanction - this is a function that prints the values passed to the monty
 * opcode.
 * @*stack: pointer to the stack of opcodes.
 * Return: void.
 */

void pall_function(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;
	size_t count = 0;
	int *values;
	size_t index;
	size_t i = 0;

	(void)number;

	while (current != NULL)
	{
		printf("%d\n", current -> n);
		current = current -> next;
	}
	values = malloc(count * sizeof(int));
	if (values == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	index = count - 1;
	while (current != NULL)
	{
		values[index] = current -> n;
		index--;
		current = current -> next;
	}
	for (i = 0; i < count; i++)
	{
		printf("%d\n", values[i]);
	}
	free(values);
}
