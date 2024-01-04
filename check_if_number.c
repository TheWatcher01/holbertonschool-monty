#include "monty.h"

/**
 * check_if_number - Checks if a string is a number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */

int check_if_number(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i = 1;
    for (; str[i]; i++)
    {
        if (isdigit(str[i]) == 0)
            return (0);
    }
    return (1);
}