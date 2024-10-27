#include <stdio.h>
#include "../utils.h"

static char* find_l(const char* s, const char* l_start)
{
    const char* p = (is_paren(*l_start) && l_start > s) ? l_start - 1 : l_start;
    for (; p > s && !is_paren(*p); p--) {
        if (is_oprtr(*p)) {
            break;
        }
    }
    return is_paren_depth_same(p, l_start) ? (char*)p : NULL;
}

static char* find_r(const char* r_start)
{
    const char* p = (is_paren(*r_start)) ? r_start + 1 : r_start;
    for (; *p && !is_paren(*p); p++) {
        if (is_oprtr(*p)) {
            break;
        }
    }
    return is_paren_depth_same(r_start, p) ? (char*)p : NULL;
}

char* find_adj_oprtr(const char* s,
                           const char* l_start, const char* r_start)
{

    char* l = l_start ? find_l(s, l_start) : NULL;
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
    return (l_start - l) <= (r - r_start) ? l : r;
}
