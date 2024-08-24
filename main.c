#include <stdio.h>
#include "main.h"
#include "./general/general.h"
#include "./workflows/arithmetic/arithmetic.h"
#include "./workflows/algebraic/algebraic.h"

char input[MAXLEN] = "11+2x*3";

struct Equation eq;
struct Parens parens;
struct Bounds bounds;
struct Switches sw;

int main(void)
{
    clean_input();
    set_workflow();
    if (sw.arithmetic) {
        solve_arithmetic();
    } else if (sw.alg_1var) {
        process_algebraic();
    }
    printf("\nSolved equation: %s\n", input);
}
         