#include "monty.h"

/**
 * pall - Prints all values on stack, starting from the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The number of the line currently being run.
 *
 * This function iterates through the stack from the top to the bottom,
 * printing each integer value. It doesn't modify the stack.
 */

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;
    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}