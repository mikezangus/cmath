#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../general/general.h"
#include "../utils/utils.h"

static bool find_position(char* c, short* scale)
{
    weigh_chars(*c, scale, '(', ')');
    return (*scale == 0 && !isdigit(*c) && !is_var(*c));
}

static char* find_left(char* s, char* op)
{
    char* p;
    short scale = 0;
    for (p = op - 1; p >= s; p--) {
        if (find_position(p, &scale)) {
            break;
        }
    }
    return (p == s) ? p : p + 1;
}

static char* find_right(char *s, char *op)
{
    char* p;
    short scale = 0;
    char* eqsign = strchr(s, '=');
    char* end = eqsign ? eqsign : s + strlen(s);
    for (p = op + 1; *p && p < end; p++) {
        if (find_position(p, &scale)) {
            break;
        }
    }
    return p;
}

static bool insert(char *s, char *op)
{
    char* l = find_left(s, op);
    char* r = find_right(s, op);
    if (!l || !r) {
        return false;
    }
    insert_str(s, "(", l);
    insert_str(s, ")", r + 1);
    return true;
}

static bool is_inside_parens(char* s, char* op)
{
    char* p_l;
    for (p_l = op - 1; p_l > s && (isdigit(*p_l) || is_var(*p_l)); p_l--) {
        ;;
    }
    char* p_r;
    char* eqsign = strchr(s, '=');
    char* end = eqsign ? eqsign : s + strlen(s);
    for (p_r = op + 1; *p_r && p_r < end && (isdigit(*p_r) || is_var(*p_r)); p_r++) {
        ;;
    }
    return (*p_l == '(' && *p_r == ')');
}

static void insert_by_op_precedent(char* s, bool (*is_prec_oprtr)(char))
{
    for (char* p = s; *p && *p != '='; p++) {
        if (is_prec_oprtr(*p) && !is_inside_parens(s, p) && insert(s, p)) {
            p += 2;
        }
    }
}

void insert_parens(char* s)
{
    insert_by_op_precedent(s, is_prec1_oprtr);
    insert_by_op_precedent(s, is_prec2_oprtr);
}
