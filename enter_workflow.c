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

Bounds b;

void format_str_alg(char* s)
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
    format_str_alg(s);
    while (true) {
        if ((get_paren_depth(s, s + strlen(s))) != 0) {
            return;
        }
        format_vars(s);
        format_str(s);
        printf("\nStarting: %s\n", s);
        if (!find_bounds(s, &b.l, &b.r)) {
            return;
        }
        char* var = find_var(s, NULL);
        if (!var) {
            if (!solve_arithmetic(s, &b)) {
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
