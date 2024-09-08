#include <stdio.h>
#include "main.h"

struct Equation eq;

int main(void)
{
    char input[STR_MAXLEN];
    printf("\nEnter input:\n> ");
    fgets(input, sizeof(input), stdin);
    clean_input(input);
    enter_workflow(input);
    printf("\nSolved equation: %s\n", input);
    return 0;
}
