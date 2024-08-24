#include <stdio.h>
#include "main.h"
#include "./general/general.h"
#include "./workflows/arithmetic/arithmetic.h"

char input[MAXLEN] = "1 * 2+3*4+4*5^6*7-8/9";

struct Equation eq;
struct Parens parens;
struct Bounds bounds;
struct Switches sw;

int main(void)
{
    clean_input();
    add_parens();
    set_workflow();
    if (sw.arithmetic) {
        solve_arithmetic();
    } else if (sw.alg_1var) {
        ;;
    }
    printf("\nSolved equation: %s\n", input);
}
