#include <math.h>
#include <stdio.h>

double calculate_oprtn(double op1, char oprtr, double op2)
{
    if (isnan(op1) || isnan(op2)) {
        return NAN;
    }
    switch (oprtr) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return (op2 == 0.0) ? NAN : op1 / op2;
        case '^': return pow(op1, op2);
        case '√': 
            return (op2 == 0 || (op1 < 0 && ((int)op2 % 2 == 0)))
                ? NAN
                : pow(op1, 1.0 / op2);
        default:
            fprintf(stderr, "\n%s | Invalid operator: %c\n", __FILE__, oprtr);
            return NAN;
    }
}
