#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../general.h"
#include "../../main.h"
#include "../../utils/utils.h"
#include "../../workflows/algebraic/algebraic.h"

static bool find_position(char* c, bool skip_parens, int* scale)
{
    if (skip_parens) {
        balance_chars(*c, scale, '(', ')');
        return *scale == 0 && !isdigit(*c) && !is_var(*c);
    }
    return !isdigit(*c) && !is_var(*c);
}

static char* find_l_bound(char* start, char* end)
{
    char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = start; p >= end; p--) {
        if (*p == ')') {
            skip_parens = true;
        }
        if (find_position(p, skip_parens, &scale)) {
            break;
        }
    }
    return p == end ? p : p + 1;
}

static char* find_r_bound(char *start)
{
    char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = start; *p && *p != '='; p++) {
        if (*p == '(') {
            skip_parens = true;
        }
        if (find_position(p, skip_parens, &scale)) {
            break;
        }
    }
    return p - 1;
}

bool find_bounds_by_highest_op(char* s, char** l_bound, char** r_bound)
{
    char* start = *s == '-' ? s + 1 : s;
    char* op = NULL;
    if (!(op = strpbrk(start, "^")) &&
        !(op = strpbrk(start, "*/")) &&
        !(op = strpbrk(start, "+-"))) {
        return false;
    }
    *l_bound = find_l_bound(op - 1, s);
    *r_bound = find_r_bound(op + 1);
    return true;
}
