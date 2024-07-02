#include <ctype.h>
#include <stdio.h>
#include "header.h"

void get_input(void)
{
    printf("\nEnter your input:\n> ");
    if (fgets(input_raw, sizeof(input_raw), stdin) != NULL) {
        printf("\nYour input: %s\n", input_raw);
    } else {
        printf("Error getting input\n");
    }
}
