#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "../utils.h"

static bool is_root_operable(double base, double expnd, double expdd)
{
    int expn = (int)expnd;
    int expd = (int)expdd;
    if (expnd != expn || expdd != expd) {
        fprintf(stderr,
                "\n%s\n"
                "Error | Failed to convert exponent doubles to ints\n"
                "  Exponent numerator double:   %f\n"
                "  Exponent numerator int:      %d\n"
                "  Exponent denominator double: %f\n"
                "  Exponent denominator int:    %d\n",
                __FILE__, expnd, expn, expdd, expd);
        return false;
    }
    if (expdd == 0) {
        fprintf(stderr,
                "\n%s\n"
                "Error | 0 denominator in root calculation\n"
                "  Base:                 %f\n"
                "  Exponent numerator:   %d\n"
                "  Exponent denominator: %d\n",
                __FILE__, base, expn, expd);
        return false;
    }
    if (base < 0 && expd % 2 == 0) {
        fprintf(stderr,
                "\n%s\n"
                "Error | Negative base with even root\n"
                "  Base:                 %f\n"
                "  Exponent numerator:   %d\n"
                "  Exponent denominator: %d\n",
                __FILE__, base, expn, expd);
        return false;
    }
    double root = pow(base, 1.0 / expd);
    double result = pow(root, expn);
    return modf(result, &(double){0}) == 0.0;
}

static bool is_pow_operable(double basen, double based,
                            double expn, double expd)
{
    if (!(based == 1.0 || isnan(based))) {
        printf("Exponent not operable. Base has denominator\n");
        return false;
    }
    if (basen == 1.0) {
        return true;
    }
    if (expd == 1.0 || isnan(expd)) {
        return true;
    }
    return is_root_operable(basen, expn, expd);
}

static bool is_div_operable(double n, double d)
{
    if (d == 0 || isnan(d)) {
        printf("Division not operable: 0 denominator\n");
        return false;
    }
    if (modf(n, &(double){0}) != 0.0 || modf(d, &(double){0}) != 0.0) {
        return true;
    }
    return fmod(n, d) == 0.0;
}

bool is_oprtn_operable(double op1n, double op1d,
                       char oprtr,
                       double op2n, double op2d)
{
    switch (oprtr) {
        case '^': return is_pow_operable(op1n, op1d, op2n, op2d);
        case '/': return is_div_operable(op1n, op2n);
        default: return true;
    }
}
