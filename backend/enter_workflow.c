#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "bounding/bounding.h"
#include "formatting/formatting.h"
#include "general/general.h"
#include "utils/utils.h"
#include "workflows/algebraic/algebraic.h"
#include "workflows/arithmetic/arithmetic.h"

static void format_str_alg(char* s)
{
    char* var = find_var(s, NULL);
    if (!var) {
        return;
    }
    format_vars(s);
    insert_eqzero(s);
    insert_parens(s);
    rearrange(s);
}

void enter_workflow(char* s)
{
    char* l_bound;
    char* r_bound;
    char* div_sign;
    format_str_alg(s);
    while (true) {
        if ((get_paren_depth(s, s + strlen(s)))) {
            return;
        }
        format_vars(s);
        format_str(s);
        l_bound = r_bound = NULL;
        if (!find_bounds(s, &l_bound, &r_bound)) {
            return;
        }
        if (!find_var(s, NULL)) {
            if (!solve_arithmetic(s, s, &l_bound, &r_bound)) {
                return;
            }
        } else {
            if (!solve_algebraic(s)) {
                return;
            }
            return;
        }
    }
}
