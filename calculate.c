#include <stdio.h>
#include "header.h"

void calculate(void)
{
    eq.result = 0;
    if (eq.sign == '+')
        eq.result = eq.n1d + eq.n2d;
    else if (eq.sign == '-')
        eq.result = eq.n1d - eq.n2d;
    printf("Result: %f\n", eq.result);
}
