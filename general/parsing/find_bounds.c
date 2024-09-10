#include <stdbool.h>
#include <stdio.h>
#include "parsing.h"

bool find_bounds(char* s, char** l_bound, char** r_bound)
{
    if (find_bounds_by_parens(s, l_bound, r_bound) ||
        find_bounds_by_highest_op(s, l_bound, r_bound)
    ) {
        return true;
    }
    return false;
}
