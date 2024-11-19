#include <math.h>
#include <stdio.h>

static double calculate_root_oprtn(double base, int expn, int expd)
{
    if (expd == 0) {
        fprintf(stderr,
                "%s\nError | Zero denominator in root calculation: %f^%d/%d\n",
                __FILE__, base, expn, expd);
        return NAN;
    }
    if (base < 0 && expd % 2 == 0) {
        fprintf(stderr,
                "%s\nError | Negative base with even root: %f^%d/%d\n",
                __FILE__, base, expn, expd);
        return NAN;
    }
    double root = pow(base, 1.0 / expd);
    return pow(root, expn);
}

double calculate_oprtn(double op1, char oprtr, double op2n, double op2d)
{
    if (isnan(op1) || isnan(op2n)) {
        return NAN;
    }
    switch (oprtr) {
        case '+': return op1 + op2n;
        case '-': return op1 - op2n;
        case '*': return op1 * op2n;
        case '/': return (op2n == 0.0) ? NAN : op1 / op2n;
        case '^': return op2d
            ? calculate_root_oprtn(op1, op2n, op2d)
            : pow(op1, op2n);
        default:
            fprintf(stderr, "\n%s | Invalid operator: %c\n", __FILE__, oprtr);
            return NAN;
    }
}
