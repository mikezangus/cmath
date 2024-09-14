#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../general/general.h"
#include "../utils/utils.h"

static bool find_position(char* c, bool scale_needed, short* scale)
{
    if (scale_needed) {
        weigh_chars(*c, scale, '(', ')');
        return (*scale == 0 && !isdigit(*c) && !char_is_var(*c));
    }
    return (!isdigit(*c) && !char_is_var(*c));
}

static char* find_left(char* s, char* op)
{
    char* p;
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
    return (p == s) ? p : p + 1;
}

static char* find_right(char* s, char* op)
{
    char* p;
    short scale = 0;
    bool scale_needed = false;
    char* eqsign = strchr(s, '=');
    char* end = eqsign ? eqsign : s + strlen(s);
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

static bool insert(char* s, char* op)
{
    char* l = find_left(s, op);
    char* r = find_right(s, op);
    if (
        (!l || !r) ||
        (l == s && *l == '(' && *r == ')') ||
        (l != s && *(l - 1) == '(' && *r == ')') ||
        (l == s && r == strchr(s, '='))
    ) {
        return false;
    } 
    insert_str(s, "(", l);
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
