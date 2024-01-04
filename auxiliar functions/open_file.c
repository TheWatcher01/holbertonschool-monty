#include "monty.h"

/**
 * open_file - Function to open a file.
 * @filename: The name of the file to open.
 *
 * This function attempts to open a file with read permissions. If the file
 * cannot be opened, it prints an error message and terminates the program
 * with a failure status.
 *
 * Return: A pointer to the opened file.
 */
FILE *open_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}