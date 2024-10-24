#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../formatting.h"
#include "../../general/general.h"
#include "../../workflows/algebraic/algebraic.h"

static bool find_position(const char* p, bool* skip_parens, int* scale)
{
    if (*skip_parens) {
        balance_chars(*p, scale, '(', ')');
        if (*scale == 0) {
            *skip_parens = false;
        }
        return false;
    }
    return !isdigit(*p) && !is_var(*p) && *p != '.';
}

static const char* find_l(const char* s, const char* oprtr)
{
    const char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = oprtr - 1; p >= s; p--) {
        if (*p == ')') {
            skip_parens = true;
        }
        if (find_position(p, &skip_parens, &scale)) {
            break;
        }
    }
    return p;
}

static const char* find_r(const char* oprtr)
{
    const char* p = (*(oprtr + 1) == '-')
        ? oprtr + 2
        : oprtr + 1;
    int scale = 0;
    bool skip_parens = false;
    for (; *p && *p != '='; p++) {
        if (*p == '(') {
            skip_parens = true;
        }
        if (find_position(p, &skip_parens, &scale)) {
            break;
        }
    }
    return p;
}

static bool parens_already_exist(const char* l,
                                 const char* oprtr,
                                 const char* r)
{
    if (!(*l == '(') && !(*r == ')')) {
        return false;
    }
    int scale = 0;
    for (const char* p = l; p <= r; p++) {
        balance_chars(*p, &scale, '(', ')');
    }
    return scale == 0;
}

static bool insert_by_oprtr(char* s, const char* oprtr)
{
    const char* l = find_l(s, oprtr);
    const char* r = find_r(oprtr);
    const char* eq_sign = strchr(s, '=');
    const char* end = eq_sign
        ? eq_sign
        : s + strlen(s);
    if (!l || !r
        || parens_already_exist(l, oprtr, r)
        || (l == s && r == end)) {
        return false;
    }
    l == s
        ? insert_str(s, "(", l)
        : insert_str(s, "(", l + 1);
    insert_str(s, ")", r + 1);
    return true;
}

static void insert_by_oprtr_prec(char* s, bool (*is_prec_oprtr)(char))
{
    for (char* p = s; *p; p++) {
        if (is_prec_oprtr(*p) && insert_by_oprtr(s, p)) {
            p += 2;
        }
    }
}

void insert_parens(char* s)
{
    insert_by_oprtr_prec(s, is_prec1_oprtr);
    insert_by_oprtr_prec(s, is_prec2_oprtr);
    insert_by_oprtr_prec(s, is_sub_oprtr);
}
