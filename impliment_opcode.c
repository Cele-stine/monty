#include "monty.h"

/**
 * push_function - a function that pushes an element into the stack.
 * @stack: the stack to push the element to.
 * @value: the element to push
 * Return: void
 */

void push_function(stack_t **stack, unsigned int value)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	newNode -> n = value;
	newNode -> prev = NULL;
	newNode -> next = (*stack);

	if (*stack != NULL)
	{
		(*stack) -> prev = newNode;
	}
	*stack = newNode;
}

/**
 * pall_function - this is a function that prints the values passed to the
 * monty opcode.
 * @stack: pointer to the stack of opcodes.
 * @number: index assigment to the elements in the stack.
 * Return: void.
 */

void pall_function(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;

	(void)number;

	while (current != NULL)
	{
		printf("%d\n", current -> n);
		current = current -> next;
	}
}
