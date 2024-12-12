#include <ctype.h>
#include <stdbool.h>
#include "../utils/utils.h"

static bool find_position(const char* p, bool skip_parens, int* scale)
{
    if (!skip_parens) {
        return !isdigit(*p) && !is_var(*p) && *p != '.';
    }
    balance_chars(*p, scale, '(', ')');
    return *scale == 0 && !isdigit(*p) && !is_var(*p) && *p != '.';
}

static char* find_l_bound(const char* start, const char* min)
{
    const char* p;
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
    return (char*)(p == min ? p : p + 1);
}

static char* find_r_bound(const char *start)
{
    const char* p;
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
    return (char*)(p - 1);
}

bool find_bounds_by_oprtr(const char* start, const char* end,
                          char** l_bound, char** r_bound)
{
    const char* op_start = (*start == '-') ? start + 1 : start;
    char* op;
    if (!(op = find_char('^', op_start, end))
        && !(op = find_char('*', op_start, end))
        && !(op = find_char('/', op_start, end))
        && !(op = find_char('+', op_start, end))
        && !(op = find_char('-', op_start, end))) {
        return false;
    }
    *l_bound = find_l_bound(op - 1, start);
    *r_bound = find_r_bound(op + 1);
    return true;
}
