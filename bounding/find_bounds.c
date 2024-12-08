#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "bounding.h"
#include "../main.h"

static bool sequence(const char* start, const char* end,
                     char** l_bound, char** r_bound)
{
    return find_bounds_by_parens(start, l_bound, r_bound)
        || find_bounds_by_oprtr(start, end, l_bound, r_bound);
}

bool find_bounds(const char* start, char** l_bound, char** r_bound)
{
    *l_bound = NULL;
    *r_bound = NULL;
    const char* eq_sign = strchr(start, '=');
    if (!sequence(start, eq_sign, l_bound, r_bound)) {
        if (!eq_sign) {
            return false;
        }
        return sequence(eq_sign + 1, NULL, l_bound, r_bound);
    }
}
