#include <stdbool.h>
#include <stdio.h>
#include "bounding.h"

bool find_bounds(char* s, char** l_bound, char** r_bound)
{
    if (!find_bounds_by_parens(s, l_bound, r_bound) &&
        !find_bounds_by_highest_op(s, l_bound, r_bound)
    ) {
        return false;
    }
    printf(
        "\nBounds: %c%c ... %c%c\n",
        *(*l_bound), *(*l_bound + 1), *(*r_bound - 1), *(*r_bound)
    );
    return true;
}
