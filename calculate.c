#include <stdio.h>
#include "header.h"

int calculate(void)
{
    eq.result = 0.0;
    switch (eq.sign) {
    case '+':
        eq.result = eq.n1d + eq.n2d;
        break;
    case '-':
        eq.result = eq.n1d - eq.n2d;
        break;
    case '*':
        eq.result = eq.n1d * eq.n2d;
        break;
    case '/':
        if (eq.n2d == 0) {
            printf("Error: Unable to divide by 0\n");
            return;
        } else {
            eq.result = eq.n1d / eq.n2d;
            break;
        }
    default:
        printf("Error: Unable to calculate.\nSign: %c\n", eq.sign);
        return 0;
    }
    printf("Result: %f\n", eq.result);
    return 0;
}
