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

