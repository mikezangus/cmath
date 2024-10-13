#include <stdbool.h>
#include <stdio.h>
#include "main.h"
#include "bounding/bounding.h"
#include "general/verifications/verifications.h"
#include "utils/utils.h"
#include "workflows/algebraic/algebraic.h"
#include "workflows/arithmetic/arithmetic.h"

Bounds b;

void enter_workflow(char* s)
{
    printf("Entering workflow\n");
    while (verify(s)) {
    // for (int i = 0; i < 5; i++) {
        printf("\n\n%s\nSolving for:\n%s\n", DASHES, s);
        if (!find_bounds(s, &b.l, &b.r)) {
            return;
        }
        char* var = find_var(b.l, b.r);
        if (!var) {
            solve_arithmetic(s, &b);
        } else {
            // process_algebraic(s);
            printf("algebraic\n");
        }
    }
}
