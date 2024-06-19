#include <stdio.h>
#include "header.h"

void calculate(void)
{
    eq.result = 0;
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
        eq.result = eq.n1d / eq.n2d;
        break;
    }
    printf("Result: %f\n", eq.result);
}
