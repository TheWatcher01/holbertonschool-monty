#include "monty.h"

/**
 * push - Adds a new element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The number to be added to the stack.
 *
 * This function creates a new stack element and adds
 * it to the top of the stack.
 * If memory allocation fails, it prints an error message
 * and exits with status EXIT_FAILURE.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
