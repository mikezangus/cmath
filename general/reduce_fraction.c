#include <math.h>
#include <stdbool.h>

static bool has_decimal(double d)
{
    double integer;
    return modf(d, &integer) != 0.0;
}

long long get_gcd(long long a, long long b)
{
    long long temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduce_fraction(double *n, double *d)
{
    if (*d == 0) {
        return;
    }
    if (has_decimal(*n) || has_decimal(*d)) {
        return;
    }
    long long gcd = get_gcd((long long)*n, (long long)*d);
    (*n) /= gcd;
    (*d) /= gcd;
}
