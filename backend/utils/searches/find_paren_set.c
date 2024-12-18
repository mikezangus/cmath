#include <stdbool.h>
#include <stdio.h>

bool find_paren_set(const char* start, char** l_paren, char** r_paren)
{
    *l_paren = *r_paren = NULL;
    for (const char* p = start; *p && *p != '='; p++) {
        if (*p == '(') {
            *l_paren = (char*)p;
        } else if (*l_paren && *p == ')') {
            *r_paren = (char*)p;
            break;
        }
    }
    if (!*l_paren || !*r_paren) {
        *l_paren = *r_paren = NULL;
        return false;
    }
    return true;
}
