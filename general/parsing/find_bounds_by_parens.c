#include <stdbool.h>
#include <stdio.h>

bool find_bounds_by_parens(char* s, char** l_bound, char** r_bound)
{
    char* left = NULL;
    char* right = NULL;
    for (char* p = s; *p && *p != '='; p++) {
        if (*p == '(') {
            left = p;
        } else if (left && *p == ')') {
            right = p;
            break;
        }
    }
    if (!left || !right) {
        return false;
    }
    *l_bound = ++left;
    *r_bound = --right;
    return true;
}
