#include <ctype.h>
#include <stdio.h>
#include "header.h"

void convert(int term_idx)
{
    printf("\n2. Convert\n");
    eq.op1d = 0.0;
    eq.op2d = 0.0;
    if (!term_idx) {
        for (int i = 0; eq.op1c[i] != '\0'; i++) {
            eq.op1d = eq.op1d * 10 + (eq.op1c[i] - '0');
        } 
    } else {
        eq.op1d = eq.result;
    }
    for (int i = 0; eq.op2c[i] != '\0'; i++) {
        eq.op2d = eq.op2d * 10 + (eq.op2c[i] - '0');
    }
    printf("Operand 1: %f\n", eq.op1d);
    printf("Operand 2: %f\n", eq.op2d);
}
