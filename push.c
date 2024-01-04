#include "monty.h"

/**
 * push - Adds a new_node element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The number to be added to the stack.
 *
 * Function creates new_node stack element and adds it to the top of the stack
 * If memory allocation fails, it prints error message and exits with
 * status EXIT_FAILURE.
 */

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed in line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = gbl_value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}