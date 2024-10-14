#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "../bounding/bounding.h"

static bool condition(char* p, bool l, bool div)
{
    char paren = l ? '(' : ')';
    char* next = l
        ? p - 1
        : p + 1;
    return !div
        ? *p == paren
        : *p == paren && *next == paren;
}

static char* find_l(char* s, char* start, bool div)
{
    for (char* p = start; p >= s; p--) {
        if (is_oprtr(*p) || *p == ')') {
            break;
        }
        if (condition(p, true, div)) {
            return p;
        }
    }
    return NULL;
}

static char* find_r(char* start, bool div)
{
    for (char* p = start; *p; p++) {
        if (is_oprtr(*p) || *p == '(') {
            break;
        }
        if (condition(p, false, div)) {
            return p;
        }   
    }
    return NULL;
}

static bool hanging_paren(char* l_bound, char* r_bound)
{
    if (*(l_bound - 1) == '(' && *(r_bound + 1) != ')') {
        collapse_str(l_bound - 1, l_bound - 1);
        return true;
    }
    if (*(l_bound - 1) != '(' && *(r_bound + 1) == ')') {
        collapse_str(r_bound + 1, r_bound + 1);
        return true;
    }
    return false;
}

static bool solo_negative(char* s, char* oprtr, char* l_bound, char* r_bound)
{
    if (!oprtr || *oprtr != '-'
        || isdigit(*(oprtr - 1))
        || !isdigit(*(oprtr + 1))) {
        return false;
    }
    char* l = find_l(s, l_bound - 1, false);
    char* r = find_r(r_bound + 1, false);
    if (!l || !r) {
        return false;
    }
    collapse_str(l, l);
    collapse_str(r - 1, r - 1);
    return true;
}

static bool no_oprtr(char* s, char* oprtr, char* l_bound, char* r_bound)
{
    if (oprtr) {
        return false;
    }
    char* l = find_l(s, l_bound - 1, false);
    char* r = find_r(r_bound + 1, false);
    if (!l || !r) {
        return false;
    }
    collapse_str(l, l);
    collapse_str(r - 1, r - 1);
    return true;
}

static bool div_oprtr(char* s, char* oprtr, char* l_bound, char* r_bound)
{
    if (oprtr && *oprtr != '/') {
        return false;
    }
    char* l = find_l(s, l_bound - 1, true);
    char* r = find_r(r_bound + 1, true);
    if (!l || !r) {
        return false;
    }
    collapse_str(l, l);
    collapse_str(r - 1, r - 1);
    return true;
}

void remove_unneeded_parens(char* s)
{
    char* l_bound = NULL;
    char* r_bound = NULL;
    while (*s) {
        if (!find_bounds_by_parens(s, &l_bound, &r_bound)) {
            return;
        }
        char* oprtr = find_oprtr(l_bound, r_bound);
        if (no_oprtr(s, oprtr, l_bound, r_bound)
            || solo_negative(s, oprtr, l_bound, r_bound)
            || div_oprtr(s, oprtr, l_bound, r_bound)
            || hanging_paren(l_bound, r_bound)) {
            s = s;
            continue;
        }
        s = r_bound + 1;
    }
}
