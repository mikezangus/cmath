#include <math.h>
#include <stdio.h>
#include "main.h"

void calculate_result(void)
{
    switch (eq.oprtr) {
    case '+':
        eq.resultd = eq.op1d + eq.op2d;
        break;
    case '-':
        eq.resultd = eq.op1d - eq.op2d;
        break;
    case '*':
        eq.resultd = eq.op1d * eq.op2d;
        break;
    case '/':
        if (eq.op2d == 0.0) {
            break;
        }
        eq.resultd = eq.op1d / eq.op2d;
        break;
    case '^':
        eq.resultd = pow(eq.op1d, eq.op2d);
        break;
    }
    printf("%f %c %f = %f\n", eq.op1d, eq.oprtr, eq.op2d, eq.resultd);
}
