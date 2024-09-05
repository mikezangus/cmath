#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../general/general.h"
#include "../utils/utils.h"

#include <stdio.h>

static bool find_position(char *c, int *scale)
{
    weigh_chars(*c, scale, '(', ')');
    return (*scale == 0 && !isdigit(*c) && *c != 'x');
}

static char* find_left(char *s, char *op)
{
    char *p;
    int scale = 0;
    for (p = op - 1; p >= s; p--) {
        if (find_position(p, &scale)) {
            break;
        }
    }
    return (p == s) ? p : p + 1;
}

static char* find_right(char *s, char *op)
{
    char *p;
    int scale = 0;
    char *eqsign = strchr(s, '=');
    char *end = eqsign ? eqsign : s + strlen(s);
    for (p = op + 1; *p && p < end; p++) {
        if (find_position(p, &scale)) {
            break;
        }
    }
    return p;
}

static bool insert(char *s, char *op)
{
    char *l = find_left(s, op);
    char *r = find_right(s, op);
    if (!l || !r) {
        return false;
    }
    insert_str(s, "(", l);
    insert_str(s, ")", r + 1);
    return true;
}

void insert_parens(char *s)
{
    for (char *p = s; *p && *p != '='; p++) {
        if (is_prec1_oprtr(*p) && insert(s, p)) {
            p += 2;
        }
    }
    for (char *p = s; *p && *p != '='; p++) {
        if (is_prec2_oprtr(*p) && insert(s, p)) {
            p += 2;
        }
    }
}
