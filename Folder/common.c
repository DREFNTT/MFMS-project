#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "common.h"
#include <string.h>

int getValidInteger(const char *prompt)
{
    char input[100];
    char *endptr;
    long value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        errno = 0;
        endptr = NULL;
        value = strtol(input, &endptr, 10);

        if (endptr == input)
        {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        while (*endptr == ' ' || *endptr == '\t')
        {
            endptr++;
        }

        if (*endptr != '\n' && *endptr != '\0')
        {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
        {
            printf("Number is out of range. Please try again.\n");
            continue;
        }

        return (int)value;
    }
}

int getValidPositiveInteger(const char *prompt)
{
    int value;

    while (1)
    {
        value = getValidInteger(prompt);

        if (value > 0)
        {
            return value;
        }

        printf("Please enter a number greater than zero.\n");
    }
}

void getValidNonEmptyString(const char *prompt, char *output, size_t size)
{
    while (1)
    {
        printf("%s", prompt);

        if (fgets(output, size, stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        output[strcspn(output, "\n")] = '\0';

        if (strlen(output) == 0)
        {
            printf("This field cannot be empty. Please try again.\n");
            continue;
        }

        return;
    }
}
