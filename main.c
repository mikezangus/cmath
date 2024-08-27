#include <stdio.h>
#include "main.h"
#include "./general/general.h"
#include "./workflows/arithmetic/arithmetic.h"
#include "./workflows/algebraic/algebraic.h"

char input[MAXLEN] = "3/2+2^2-1";

struct Equation eq;
struct Parens parens;
struct Bounds bounds;
struct Switches sw;

int main(void)
{
    clean_input();
    set_workflow();
    if (sw.arithmetic) {
        if (process_arithmetic()) {
            printf("\nSolved equation: %s\n", input);
            return 0;
        } else {
            return -1;
        }
    } else if (sw.alg_1var) {
        if (process_arithmetic()) {
            printf("\nSolved equation: %s\n", input);
            return 0;
        } else {
            return -1;
        }
    }
}
