#include "monty.h"

/**
 * opcode_handle - Handles the opcode
 * @opcode: The opcode to handle
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number
 *
 * Description: This function handles the opcode. It checks if the opcode
 * matches any of the predefined ones and if so, calls the corresponding
 * function. If the opcode does not match any of the predefined ones,
 * it prints an error message and exits the program.
 */

void opcode_handle(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t instruction[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        /* Add more opcodes here */
        {NULL, NULL}
    };
    int i;

    for (i = 0; instruction[i].opcode; i++)
    {
        if (strcmp(opcode, instruction[i].opcode) == 0)
        {
            instruction[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}