#include <ctype.h>
#include <stdio.h>
#include "header.h"

void get_input(void)
{
    printf("\nEnter your input:\n> ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("\nYour input: %s\n", input);
    } else {
        printf("Error getting input\n");
    }
}
