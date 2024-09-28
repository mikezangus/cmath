#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../general.h"
#include "../../workflows/algebraic/algebraic.h"

static bool find_position(char* c, bool scale_needed, short* scale)
{
    if (scale_needed) {
        balance_chars(*c, scale, '(', ')');
        return (*scale == 0 && !isdigit(*c) && !is_var(*c));
    }
    return (!isdigit(*c) && !is_var(*c));
}

static char* find_left(char* start, char* end)
{
    char* p;
    short scale = 0;
    bool scale_needed = false;
    for (p = start; p >= end; p--) {
        if (*p == ')') {
            scale_needed = true;
        }
        if (find_position(p, scale_needed, &scale)) {
            break;
        }
    }
    return (p == end) ? p : p + 1;
}

static char* find_right(char* s, char *start)
{
    char* p;
    short scale = 0;
    bool scale_needed = false;
    char* eqsign = strchr(s, '=');
    char* end = eqsign ? eqsign : s + strlen(s);
    for (p = start; *p && p < end; p++) {
        if (*p == '(') {
            scale_needed = true;
        }
        if (find_position(p, scale_needed, &scale)) {
            break;
        }
    }
    return p - 1;
}

bool find_bounds_by_highest_op(char* s, char** l_bound, char** r_bound)
{
    char* op = NULL;
    if (!(op = strpbrk(s, "^")) &&
        !(op = strpbrk(s, "*/")) &&
        !(op = strpbrk(s, "+-"))
    ) {
        return false;
    }
    *l_bound = find_left(op - 1, s);
    *r_bound = find_right(s, op + 1);
    return true;
}
