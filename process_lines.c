#include "monty.h"

/**
 * process_lines - Function to process each line of the file.
 * @file: The file to process.
 * @stack: Double pointer to the stack to be manipulated.
 *
 * This function reads each line of the file, tokenizes the line to get the opcode,
 * and then handles the opcode accordingly. If the opcode is "push", it pushes an
 * element onto the stack. For all other opcodes, it calls the function opcode_handle.
 */
void process_lines(FILE *file, stack_t **stack)
{
    char *line = NULL, *opcode;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t\r");

        if (opcode != NULL && opcode[0] != '#')
        {
            if (strcmp(opcode, "push") == 0)
            {
                push(stack, line_number);
            }
            else
            {
                opcode_handle(opcode, stack, line_number);
            }
        }
    }
    if (line)
        free(line);
}