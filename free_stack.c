#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: The stack to be freed.
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}