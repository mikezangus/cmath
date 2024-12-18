#include <stdbool.h>
#include <stdio.h>
#include "../utils/utils.h"

bool find_bounds_by_parens(const char* start, char** l_bound, char** r_bound)
{
    char* l_paren = NULL;
    char* r_paren = NULL;
    if (!find_paren_set(start, &l_paren, &r_paren)) {
        return false;
    }
    *l_bound = l_paren + 1;
    *r_bound = r_paren - 1;
    return true;
}
