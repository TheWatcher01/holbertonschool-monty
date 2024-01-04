#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node;
	int temp_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_node = *stack;
	temp_n = temp_node->n;
	temp_node->n = temp_node->next->n;
	temp_node->next->n = temp_n;
}
