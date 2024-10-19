#include <math.h>
#include <stdbool.h>

bool oprtn_is_divisible(double num, double den)
{
    if (den == 0) {
        return false;
    }
    double int1, int2;
    if (modf(num, &int1) != 0.0 || modf(den, &int2) != 0.0) {
        return true;
    }
    return fmod(num, den) == 0.0;
}
