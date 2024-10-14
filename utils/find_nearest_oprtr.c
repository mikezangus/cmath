#include <stdio.h>
#include "utils.h"

static char* find_l(char* s, char* l_start)
{
    for (char* p = l_start; p > s && *p != '(' && *p != ')'; p--) {
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

char* find_nearest_oprtr(char* s, char* l_start, char* r_start)
{
    l_start && is_paren(*l_start) && l_start != s
        ? l_start--
        : l_start;
    r_start && is_paren(*r_start)
        ? r_start++
        : r_start;
    char* l = l_start
        ? find_l(s, l_start)
        : NULL;
    char* r = r_start
        ? find_r(r_start)
        : NULL;
    if (!l && !r) {
        return NULL;
    }
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    return (l_start - l) <= (r - r_start) ? l : r;
}
