#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../utils/utils.h"

static bool solo_num(char** l_paren, char** r_paren, const char* start)
{
    /* e.g. 1+(-2)+3 -> 1+-2+3 */
    if (!find_paren_set(start, l_paren, r_paren)
        || !l_paren
        || !r_paren
        || find_oprtr(*l_paren + 1, *r_paren - 1)) {
        return false;
    }
    return *(*l_paren) == '(' && *(*r_paren) == ')';;
}

static bool enclosed_neg_sign(char** l_paren, char** r_paren,
                              const char* start, const char* src)
{
    /* e.g. (-(1*2)) -> -(1*2) */
    if (!find_paren_set(start, l_paren, r_paren)
        || !l_paren
        || !r_paren
        || *(l_paren - 2) < src
        || *(*l_paren - 1) != '-'
        || *(*l_paren - 2) != '('
        || *(*r_paren + 1) != ')') {
        return false;
    }
    return *(*l_paren -= 2) == '(' && *(*r_paren += 1) == ')';
}

static bool double_parens(char** l_paren, char** r_paren, const char* start)
{
    /* e.g. ((1*2)) -> (1*2) */
    char* l = find_char('(', start, NULL);
    if (!l || *(++l) != '(') {
        return false;
    }
    int scale = 0;
    char* r = l;
    for (; *r; r++) {
        balance_chars(*r, &scale, '(', ')');
        if (scale == 0) {
            break;
        }
    }
    if (*r != ')' || *(r + 1) != ')') {
        return false;
    }
    *l_paren = l;
    *r_paren = r;
    return *(*l_paren = l) == '(' && *(*r_paren = r) == ')';
}

bool remove_unneeded_parens(char* s)
{
    bool formatted = false;
    const char* p = s;
    char* l_paren;
    char* r_paren;
    while ((p = strchr(p, '('))) {
        if (solo_num(&l_paren, &r_paren, p)
            || enclosed_neg_sign(&l_paren, &r_paren, p, s)
            || double_parens(&l_paren, &r_paren, p)) {
            collapse_str(l_paren, l_paren);
            collapse_str(r_paren - 1, r_paren - 1);
            formatted = true;
            p = s;
        } else {
            p++;
        }
    }
    return formatted;
}
