#include <stdio.h>
#include "main.h"

struct Equation eq;

int main(void)
{
    char input[STR_MAXLEN];
    printf("\nEnter input:\n> ");
    fgets(input, sizeof(input), stdin);
    remove_spaces(input);
    enter_workflow(input);
    printf("\nSolved equation: %s\n", input);
    return 0;
}

/*
((x^2)+2+(x^2))+((x^3)-3+((x^4)+4+(x^4))+(x^3))=0
*/

/*
(x^2)+2+(x^2)
*/
