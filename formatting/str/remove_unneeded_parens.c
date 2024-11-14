#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"

static bool solo_neg_num(const char* oprtr,
                         const char* l_paren, const char* r_paren)
{
    if (*oprtr != '-') {
        return false;
    }
    if ((oprtr - 1 == l_paren) && isdigit(*(oprtr + 1))) {
        return true;
    }
    return false;
}

static bool enclosed_neg_sign(const char* s, char** l_paren, char** r_paren)
{
    if (*(l_paren - 2) < s) {
        return false;
    }
    if (*(*l_paren - 1) == '-'
        && *(*l_paren - 2) == '('
        && *(*r_paren + 1) == ')') {
        (*l_paren)-=2;
        (*r_paren)++;
        return true;
    }
    return false;
}

static bool double_parens(const char* l_paren, const char* r_paren)
{
    if (*(l_paren - 1) == '(' && *(r_paren + 1) == ')') {
        return true;
    }
    return false;
}

static bool double_outer_parens(const char* s,
                                char** l_paren, char** r_paren)
{
    const char* end = s + strlen(s) - 1;
    if (*s == '(' && *(s + 1) == '(' && *(end - 1) == ')' && *end == ')') {
        *l_paren = (char*)s;
        *r_paren = (char*)end;
        return true;
    }
    return false;
}

static bool equal_depth_outer_parens(const char* s,
                                     char** l_paren, char** r_paren)
{
    const char* end = s + strlen(s) - 1;
    if (*s != '(' && *end != ')') {
        return false;
    }
    int scale = 0;
    for (const char* p = s; *p && p <= end; p++) {
        balance_chars(*p, &scale, '(', ')');
        if (scale == 0) {
            if (p != end) {
                return false;
            }
            *l_paren = (char*)s;
            *r_paren = (char*)end;
            return true;
        }
    }
    return false;
}

void remove_unneeded_parens(char* s)
{
    char* p = s;
    char* l_paren;
    char* r_paren;
    while (*p) {
        l_paren = r_paren = NULL;
        if (!find_paren_set(p, &l_paren, &r_paren)) {
            return;
        }
        const char* oprtr = find_oprtr(l_paren + 1, r_paren - 1);
        if (!oprtr
            || solo_neg_num(oprtr, l_paren, r_paren)
            || enclosed_neg_sign(s, &l_paren, &r_paren)
            || double_parens(l_paren, r_paren)
            || double_outer_parens(s, &l_paren, &r_paren)) {
            collapse_str(l_paren, l_paren);
            collapse_str(r_paren - 1, r_paren - 1);
            p = s;
        } else {
            p = r_paren + 1;
        }
    }
}
