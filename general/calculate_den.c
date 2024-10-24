#include "general.h"
#include "../utils/utils.h"

double calculate_den(double* n1, double* d1, char oprtr, double* n2, double* d2)
{
    if (!is_prec3_oprtr(oprtr)) {
        return calculate_oprtn(*d1, oprtr, *d2);
    }
    equate_denoms(n1, d1, n2, d2);
    return *d1;
}
