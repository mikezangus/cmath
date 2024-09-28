#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../general/general.h"
#include "../utils/utils.h"
#include "../workflows/algebraic/algebraic.h"

static bool find_position(const char* c, bool scale_needed, short* scale)
{
    if (scale_needed) {
        balance_chars(*c, scale, '(', ')');
        return (*scale == 0 && !isdigit(*c) && !is_var(*c));
    }
    return !isdigit(*c) && !is_var(*c);
}

static const char* find_left(const char* s, const char* op)
{
    const char* p;
    short scale = 0;
    bool scale_needed = false;
    for (p = op - 1; p >= s; p--) {
        if (*p == ')') {
            scale_needed = true;
        }
        if (find_position(p, scale_needed, &scale)) {
            break;
        }
    }
    return p;
}

static const char* find_right(const char* s, const char* op)
{
    const char* p;
    short scale = 0;
    bool scale_needed = false;
    const char* eqsign = strchr(s, '=');
    const char* end = eqsign ? eqsign : s + strlen(s);
    for (p = op + 1; *p && p < end; p++) {
        if (*p == '(') {
            scale_needed = true;
        }
        if (find_position(p, scale_needed, &scale)) {
            break;
        }
    }
    return p;
}

static bool insert(char* s, const char* op)
{
    const char* l = find_left(s, op);
    const char* r = find_right(s, op);
    if (
        !l ||
        !r ||
        *l == '(' && *r == ')' ||
        l == s && r == strchr(s, '=')
    ) {
        return false;
    }
    l == s ? insert_str(s, "(", l) : insert_str(s, "(", l + 1);
    insert_str(s, ")", r + 1);
    return true;
}

static void insert_by_op_precedent(char* s, bool (*is_prec_oprtr)(char))
{
    for (char* p = s; *p && *p != '='; p++) {
        if (is_prec_oprtr(*p) && insert(s, p)) {
            p += 2;
        }
    }
}

void insert_parens(char* s)
{
    insert_by_op_precedent(s, is_prec1_oprtr);
    insert_by_op_precedent(s, is_prec2_oprtr);
}
