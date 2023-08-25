#include "monty.h"

/**
 * push_function - a function that pushes an element into the stack.
 * @*stack: the stack to push the element to.
 * @line_number: the element to push
 * Return: void
 */

void push_function(stack_t **stack, unsigned int value)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode -> n = value;
	newNode -> prev = NULL;
	newNode -> next = *stack;
	if (*stack != NULL)
	{
		newNode -> next = (*stack);
	}
	*stack = newNode;
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
