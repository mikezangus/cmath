#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../general/general.h"
#include "../utils/utils.h"
#include "../workflows/algebraic/algebraic.h"

static bool find_position(const char* p, bool skip_parens, int* scale)
{
    if (!skip_parens) {
        return !isdigit(*p) && !is_var(*p);
    }
    balance_chars(*p, scale, '(', ')');
    return (*scale == 0 && !isdigit(*p) && !is_var(*p));
}

static const char* find_l(const char* s, const char* oprtr)
{
    const char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = oprtr; p >= s; p--) {
        if (*p == ')') {
            skip_parens = true;
        }
        if (find_position(p, skip_parens, &scale)) {
            break;
        }
    }
    return p;
}

static const char* find_r(const char* s, const char* oprtr)
{
    const char* p;
    int scale = 0;
    bool skip_parens = false;
    for (p = oprtr; *p && *p != '='; p++) {
        if (*p == '(') {
            skip_parens = true;
        }
        if (find_position(p, skip_parens, &scale)) {
            break;
        }
    }
    return p;
}

static bool insert(char* s, const char* oprtr)
{
    const char* l = find_l(s, oprtr - 1);
    const char* r = find_r(s, oprtr + 1);
    if (!l || !r
        || (*l == '(' && *r == ')')
        || (l == s && r == strchr(s, '=')))
    {
        return false;
    }
    l == s ? insert_str(s, "(", l) : insert_str(s, "(", l + 1);
    insert_str(s, ")", r + 1);
    return true;
}

static void insert_by_oprtr_prec(char* s, bool (*is_prec_oprtr)(char))
{
    for (char* p = s; *p; p++) {
        if (is_prec_oprtr(*p) && insert(s, p)) {
            p += 2;
        }
    }
}

void insert_parens(char* s)
{
    insert_by_oprtr_prec(s, is_prec1_oprtr);
    insert_by_oprtr_prec(s, is_prec2_oprtr);
}
