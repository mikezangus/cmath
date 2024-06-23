#include <stdio.h>
#include <math.h>
#include "header.h"

int calculate(void)
{
    printf("\n3. Calculate\n");
    eq.result = 0.0;
    switch (eq.oprtr) {
    case '+':
        eq.result = eq.op1d + eq.op2d;
        break;
    case '-':
        eq.result = eq.op1d - eq.op2d;
        break;
    case '*':
        eq.result = eq.op1d * eq.op2d;
        break;
    case '/':
        if (eq.op2d == 0) {
            printf("Error: Attempted divide by 0\n");
            return 0;
        } else {
            eq.result = eq.op1d / eq.op2d;
            break;
        }
    case '^':
        eq.result = pow(eq.op1d, eq.op2d);
        break;
    default:
        printf("Error: Unable to calculate.\nSign: %c\n", eq.oprtr);
        return 0;
    }
    printf("Term result: %f\n----------------------------------------\n", eq.result);
    return 1;
}
