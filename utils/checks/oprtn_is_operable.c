#include <math.h>
#include <stdbool.h>
#include "../utils.h"

bool oprtn_is_operable(double num, char oprtr, double den)
{
    switch (oprtr) {
        case '/': return oprtn_is_divisible(num, den);
        default: return true;
    }
}
