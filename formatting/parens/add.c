#include <stdio.h>
#include <string.h>
#include "../formatting.h"

static char* find_l(char* start, char* min)
{
    if (!is_num(start, NULL)) {
        return NULL;
    }
    char* p;
    for (p = start; p > min && is_num(p, NULL); p--) {
        ;;
    }
    return p == min ? p : p + 1;
}

static char* find_r(char* start)
{
    if (!is_num(start, start)) {
        return NULL;
    }
    char* p;
    for (p = start; *p && is_num(p, start); p++) {
        ;;
    }
    return p;
}

void add_parens(char* s)
{
    char* p = s;
    while (*p) {
        char* oprtr = strchr(p, '/');
        if (!oprtr) {
            return;
        }
        char* l = find_l(oprtr - 1, s);
        char* r = find_r(oprtr + 1);
        if (l && r && *l != '(' && *r != ')') {
            insert_str(s, "(", l);
            insert_str(s, ")", r + 1);
            p = r + 2;
        } else {
            p = oprtr + 1;
        }
    }
}