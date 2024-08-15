#include <stdio.h>
#include <stdbool.h>
#include "header.h"

static double convert(char s[])
{
    double result = 0.0;
    double divisor = 10.0;
    bool fractional = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') {
            fractional = true;
            continue;
        }
        int digit = s[i] - '0';
        if (!fractional) {
            result = result * 10 + digit;
        } else {
            result += digit / divisor;
            divisor *= 10;
        }
    }
    return result;
}

void convert_str_to_d(void)
{
    eq.op1d = eq.op2d = eq.resultd = 0.0;
    eq.op1d = convert(eq.op1s);
    eq.op2d = convert(eq.op2s);
}
