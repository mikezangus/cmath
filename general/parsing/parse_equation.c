#include <stdbool.h>
#include <stdio.h>
#include "parsing.h"
#include "../general.h"
#include "../../main.h"
#include "../../utils/utils.h"

static char* parse_oprtr(char* start, char* end)
{
    for (char* p = start; *p && p <= end; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

static void parse_oprnd(char* start, char* end, char* out)
{
    for (char* p = start; *p && p <= end; p++, out++) {
        *out = *p;
    }
    *out = '\0';
}

bool parse_equation(char* s, char** l_bound, char** r_bound, char* op1, char* oprtr, char *op2)
{
    if (!find_bounds_by_parens(s, l_bound, r_bound) &&
        !find_bounds_by_highest_op(s, l_bound, r_bound)
    ) {
        return false;
    }
    char* p_oprtr = parse_oprtr(*l_bound, *r_bound);
    *oprtr = *p_oprtr;
    parse_oprnd(*l_bound, p_oprtr - 1, op1);
    parse_oprnd(p_oprtr + 1, *r_bound, op2);
    return true;
}
