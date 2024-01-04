#include "monty.h"

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top of the stack
 *
 * Return: Nothing!
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
