#include <math.h>
#include <stdio.h>

void calculate_result(double op1, char oprtr, double op2, double* result)
{
    switch (oprtr) {
    case '+':
        *result = op1 + op2;
        break;
    case '-':
        *result = op1 - op2;
        break;
    case '*':
        *result = op1 * op2;
        break;
    case '/':
        if (op2 == 0.0) {
            break;
        }
        *result = op1 / op2;
        break;
    case '^':
        *result = pow(op1, op2);
        break;
    }
    printf("\nCalculation:\n%.2f %c %.2f = %.2f\n", op1, oprtr, op2, *result);
}
