#include <stdbool.h>
#include <string.h>
#include "../utils/utils.h"

static bool find_insert_pos(const char* p, bool* skip_parens, int* scale)
{
    if (*skip_parens) {
        balance_chars(*p, scale, '(', ')');
        if (*scale == 0) {
            *skip_parens = false;
        }
        return false;
    }
    return is_oprtr(*p) || is_paren(*p);
}

static char* find_l(const char* s, const char* oprtr)
{
    const char* p = (*(oprtr - 1) != '-') ? oprtr - 1 : oprtr - 2;
    int scale = 0;
    bool skip_parens = false;
    for (; p > s && *p != '='; p--) {
        if (*p == ')') {
            skip_parens = true;
        }
        if (find_insert_pos(p, &skip_parens, &scale)) {
            break;
        }
    }
    return (char*)((p > s && *p == '-' && *(p - 1) == '(') ? p - 1 : p);
}

static char* find_r(const char* oprtr)
{
    const char* p = (*(oprtr + 1) != '-') ? oprtr + 1 : oprtr + 2;
    int scale = 0;
    bool skip_parens = false;
    for (; *p && *p != '='; p++) {
        if (*p == '(') {
            skip_parens = true;
        }
        if (find_insert_pos(p, &skip_parens, &scale)) {
            break;
        }
    }
    return (char*)p;
}

static bool insert_by_oprtr(char* s, const char* oprtr)
{
    if (oprtr == s || is_oprtr(*(oprtr - 1))) {
        return false;
    }
    char* l = find_l(s, oprtr);
    char* r = find_r(oprtr);
    if ((*l == '(' && *r == ')') || find_char('=', l + 1, r - 1)) {
        return false;
    }
    insert_str(s, (l == s) ? l : l + 1, "(");
    insert_str(s, r + 1, ")");
    return true;
}

static bool insert_by_oprtr_prec(char* s, bool (*is_prec_oprtr)(char))
{
    bool formatted = false;
    for (char* p = s; *p; p++) {
        if (is_prec_oprtr(*p) && insert_by_oprtr(s, p)) {
            formatted = true;
            p += 2;
        }
    }
    return formatted;
}

bool insert_parens(char* s)
{
    return insert_by_oprtr_prec(s, is_prec1_oprtr)
        | insert_by_oprtr_prec(s, is_prec2_oprtr);
}
