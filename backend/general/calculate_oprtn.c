#include <math.h>
#include <stdio.h>

static double calculate_root_oprtn(double base, double expnd, double expdd)
{
    int expn = (int)expnd;
    int expd = (int)expdd;
    double root = pow(base, 1.0 / expd);
    return pow(root, expn);
}

double calculate_oprtn(double op1, char oprtr, double op2n, double op2d)
{
    if (isnan(op1) || isnan(op2n) || (!isnan(op2d) && op2d != (int)op2d)) {
        fprintf(stderr, "\n%s\n Error | Invalid operands\n", __FILE__);
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
            fprintf(stderr,
                    "\n%s\nError | Invalid operator: %c\n",
                    __FILE__, oprtr);
            return NAN;
    }
}
