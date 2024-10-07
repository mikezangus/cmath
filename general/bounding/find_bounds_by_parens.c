#include <stdbool.h>
#include <stdio.h>
#include "../../main.h"

bool find_bounds_by_parens(char* s, Bounds* b)
{
    char* l_paren = NULL;
    char* r_paren = NULL;
    for (char* p = s; *p && *p != '='; p++) {
        if (*p == '(') {
            l_paren = p;
        } else if (l_paren && *p == ')') {
            r_paren = p;
            break;
        }
    }
    if (!l_paren || !r_paren) {
        return false;
    }
    b->l = l_paren + 1;
    b->r = r_paren - 1;
    return true;
}

bool find_bounds_by_parens_backwards(char* s, char** l_bound, char** r_bound)
{
    char* r_paren = NULL;
    char* l_paren = NULL;
    for (char* p = s; p >= s; p--) {
        if (*p == ')') {
            r_paren = p;
        } else if (r_paren && *p == '(') {
            l_paren = p;
            break;
        }
    }
    if (!r_paren || !l_paren) {
        return false;
    }
    *l_bound = l_paren;
    *r_bound = r_paren;
    return true;
}
