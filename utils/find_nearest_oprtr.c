#include <stdio.h>
#include "utils.h"

static char* find_l(char* s, char* l_bound)
{
    for (char* p = l_bound; p > s && *p != '(' && *p != ')'; p--) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

static char* find_r(char* r_start)
{
    for (char* p = r_start; *p && *p != '(' && *p != ')'; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

char* find_nearest_oprtr(char* s, char* l_bound, char* r_start)
{
    char* l = l_bound ? find_l(s, l_bound) : NULL;
    char* r = r_start ? find_r(r_start) : NULL;
    if (!l && !r) {
        return NULL;
    }
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    return (l_bound - l) <= (r - r_start) ? l : r;
}
