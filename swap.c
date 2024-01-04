#include "monty.h"

/**
* swap - Swaps the top two elements of the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: The line number where the error occurred.
*/

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->prev = temp;
    (*stack)->next = temp->next;
    temp->prev = NULL;
    temp->next = *stack;
    if ((*stack)->next)
        (*stack)->next->prev = *stack;
    *stack = temp;
}