
#include <stdio.h>
#include "../main.h"

void equate_denoms(double n1, double d1, double n2, double d2)
{
    if (d1 != d2) {
        eq.op1nd = n1 * d2;
        eq.op2nd = n2 * d1;
        eq.op1dd = eq.op2dd = d1 * d2;
        printf("\nEquated denoms:\n%.2f/%.2f %c %.2f/%.2f\n", eq.op1nd, eq.op1dd, eq.oprtr, eq.op2nd, eq.op2dd);
    }
}
