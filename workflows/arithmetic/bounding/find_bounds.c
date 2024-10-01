#include <stdbool.h>
#include <stdio.h>
#include "bounding.h"
#include "../parsing/parsing.h"

bool find_bounds_ar(char* s, char** l_bound, char** r_bound)
{
    if (!find_bounds_by_parens_ar(s, l_bound, r_bound) &&
        !find_bounds_by_highest_op_ar(s, l_bound, r_bound)
    ) {
        return false;
    }
    printf("Bounds: %c%c ... %c%c\n", *(*l_bound), *(*l_bound + 1), *(*r_bound - 1), *(*r_bound));
    return true;
}