#include <stdio.h>
#include "../utils.h"

static char* find_l(const char* src, const char* l_bound)
{
    if (l_bound && l_bound > src) {
        if (is_oprtr(*(--l_bound))) {
            return (char*)l_bound;
        }
        if (*l_bound == '(' && l_bound > src && is_oprtr(*(--l_bound))) {
            return (char*)l_bound;
        }
    }
    return NULL;
}

static char* find_r(const char* r_bound)
{
    if (r_bound && *(++r_bound)) {
        if (is_oprtr(*(r_bound))) {
            return (char*)r_bound;
        }
        if (*r_bound == ')' && *(++r_bound) && is_oprtr(*r_bound)) {
            return (char*)r_bound;
        }
    }
    return NULL;
}

char* find_adj_oprtr(const char* src, const char* l_bound, const char* r_bound)
{
    char* l = l_bound ? find_l(src, l_bound) : NULL;
    char* r = r_bound ? find_r(r_bound) : NULL;
    return l ? l : r;
}
