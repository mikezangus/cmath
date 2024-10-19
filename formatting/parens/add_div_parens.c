#include <stdio.h>
#include <string.h>
#include "../formatting.h"

static const char* find_l(const char* start, const char* min)
{
    if (!is_num(start, NULL)) {
        return NULL;
    }
    const char* p;
    for (p = start; p > min && is_num(p, NULL); p--) {
        ;;
    }
    return p == min ? p : p + 1;
}

static const char* find_r(const char* start)
{
    if (!is_num(start, start)) {
        return NULL;
    }
    const char* p;
    for (p = start; *p && is_num(p, start); p++) {
        ;;
    }
    return p;
}

void add_div_parens(char* s)
{
    const char* p = s;
    while (*p) {
        const char* oprtr = strchr(p, '/');
        if (!oprtr) {
            return;
        }
        const char* l = find_l(oprtr - 1, s);
        const char* r = find_r(oprtr + 1);
        if (l && r && *l != '(' && *r != ')') {
            insert_str(s, "(", l);
            insert_str(s, ")", r + 1);
            p = r + 2;
        } else {
            p = oprtr + 1;
        }
    }
}
