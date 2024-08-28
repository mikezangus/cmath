
#include <stdio.h>
#include "../main.h"

int get_gcd(int a, int b)
{
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduce_fraction(double *n, double *d)
{
    int gcd = get_gcd(*n, *d);
    (*n) /= gcd;
    (*d) /= gcd;
    printf("\nReduced fraction:\n%.2f/%.2f\n", *n, *d);
}
