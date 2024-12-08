#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void equate_denoms(double* n1, double* d1, double* n2, double* d2)
{
    if (isnan(*d1)) {
        *d1 = 1.0;
    }
    if (isnan(*d2)) {
        *d2 = 1.0;
    }
    if (*d1 == 0 || *d2 == 0 || isinf(*d1) || isinf(*d2)) {
        fprintf(stderr,
                "\n%s\nInvalid denominator(s):"
                "  Fraction 1: %.2f/%.2f\n"
                "  Fraction 2: %.2f/%.2f\n",
                __FILE__, *n1, *d1, *n2, *d2);
        exit(1);
    }
    if (*d1 == *d2) {
        return;
    }
    *n1 = *n1 * *d2;
    *n2 = *n2 * *d1;
    *d1 = *d2 = *d1 * *d2;
}
