#include "monty.h"

/**
 * check_args - Function to check the number of arguments passed to the program.
 * @argc: Argument count.
 *
 * This function checks if the correct number of arguments has been passed to the program.
 * If not, it prints an error message and terminates the program with a failure status.
 */
void check_args(int argc)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
}