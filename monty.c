#include "monty.h"
int gbl_value = 0;

/**
 * main - Main function to interpret Monty byte codes.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Function opens Monty byte code file, reads each line,
 * and executes opcode on each line.
 * If file cannot be opened, or if unknown instruction is encountered,
 * it prints error message and exits with status EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL, *opcode, *n_str;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t\r");
        if (opcode != NULL && opcode[0] != '#')
        {
            if (strcmp(opcode, "push") == 0)
            {
                n_str = strtok(NULL, " \n\t\r");
                if (n_str == NULL || isdigit(*n_str) == 0)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                gbl_value = atoi(n_str);
            }
            opcode_handle(opcode, &stack, line_number);
        }
    }

    fclose(file);
    if (line)
        free(line);
    free_stack(stack);
    return (EXIT_SUCCESS);
}