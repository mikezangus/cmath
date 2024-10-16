#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"
#include "../workflows/algebraic/algebraic.h"

static bool find_position(const char* p, bool skip_parens, int* scale)
{
    if (!skip_parens) {
        return !isdigit(*p) && !is_var(*p) && *p != '.';
    }
    balance_chars(*p, scale, '(', ')');
    return *scale == 0 && !isdigit(*p) && !is_var(*p) && *p != '.';
}

static char* find_l_bound(char* start, char* min)
{
    char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = start; p >= min; p--) {
        if (*p == ')') {
            skip_parens = true;
        }
        if (find_position(p, skip_parens, &scale)) {
            break;
        }
    }
    return p == min ? p : p + 1;
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

bool find_bounds_by_highest_oprtr(char* start, char** l_bound, char** r_bound)
{
    char* op_start = *start == '-' ? start + 1 : start;
    char* op = NULL;
    if (!(op = strpbrk(op_start, "^")) &&
        !(op = strpbrk(op_start, "*/")) &&
        !(op = strpbrk(op_start, "+-"))) {
        return false;
    }
    *l_bound = find_l_bound(op - 1, start);
    *r_bound = find_r_bound(op + 1);
    return true;
}
