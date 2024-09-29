#include <stdbool.h>
#include <stdio.h>
#include "general.h"
#include "../utils/utils.h"

static bool find_parens(char* s, char** l_paren, char** r_paren)
{
    for (char* p = s; *p; p++) {
        if (*p == '(') {
            *l_paren = p;
        } else if (*p == ')' && *l_paren) {
            *r_paren = p;
            break;
        }
    }
    return *l_paren && *r_paren;
}

void remove_unnecessary_parens(char* s)
{
    char* p = s;
    while (*p) {
        char* l_paren = NULL;
        char* r_paren = NULL;
        if (!find_parens(p, &l_paren, &r_paren)) {
            return;
        }
        if (find_oprtr(l_paren, r_paren)) {
            p = r_paren;
            continue;
        }
        collapse_str(l_paren, l_paren);
        collapse_str(r_paren - 1, r_paren - 1);
        p = r_paren - 2;
    }
}
