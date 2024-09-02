#include <stdio.h>
#include "main.h"
#include "./workflows/arithmetic/arithmetic.h"
#include "./workflows/algebraic/algebraic.h"

struct Flows flows;

int main(void)
{
    char input[STR_MAXLEN];
    printf("\nEnter input:\n> ");
    fgets(input, sizeof(input), stdin);
    clean_input(input);
    set_workflow(input);
    if (flows.arithmetic) {
        process_arithmetic(input);
    } else if (flows.alg_1var) {
        process_algebraic(input);
    } else {
        return 1;
    }
    printf("\nSolved equation: %s\n", input);
    return 0;
}
