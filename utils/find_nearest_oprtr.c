#include <stdio.h>
#include "utils.h"

static char* find_from_left(char* s, char* l_bound)
{
    for (char* p = l_bound - 2; p > s && *p != '(' && *p != ')'; p--) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

static char* find_from_right(char* r_bound)
{
    for (char* p = r_bound + 2; *p && *p != '(' && *p != ')'; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

char* find_nearest_oprtr(char* s, char* l_bound, char* r_bound)
{
    char* l = l_bound ? find_from_left(s, l_bound) : NULL;
    char* r = r_bound ? find_from_right(r_bound) : NULL;
    if (!l && !r) {
        return NULL;
    }
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    return (l_bound - l) <= (r - r_bound) ? l : r;
}
