#include <stdbool.h>
#include <stdio.h>
#include "bounding.h"
#include "../main.h"

bool find_bounds(const char* start, char** l_bound, char** r_bound)
{
    *l_bound = NULL;
    *r_bound = NULL;
    if (!find_bounds_by_parens(start, l_bound, r_bound)
        && !find_bounds_by_oprtr(start, l_bound, r_bound)) {
        return false;
    }
    printf("\nBounds: %.2s ... %.2s\n", *l_bound, *r_bound - 1);
    return true;
}
