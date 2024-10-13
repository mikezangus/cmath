#include <stdbool.h>
#include <stdio.h>
#include "../main.h"

bool find_bounds_by_parens(char* start, char** l_bound, char** r_bound)
{
    char* l_paren = NULL;
    char* r_paren = NULL;
    for (char* p = start; *p && *p != '='; p++) {
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
    *l_bound = l_paren + 1;
    *r_bound = r_paren - 1;
    return true;
}
