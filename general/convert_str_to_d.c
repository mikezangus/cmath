#include "../main.h"

static double convert(char *s)
{
    int fractional = 0;
    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;

    for (char *p = s; *p != '\0'; p++) {
        if (*p == '.') {
            fractional = 1;
            continue;
        }
        digit = *p - '0';
        if  (!fractional) {
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
