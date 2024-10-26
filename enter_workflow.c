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

void enter_workflow(char* s)
{
    while (true) {
        if (!is_paren_depth_same(s, s + strlen(s))) {
            return;
        }
        format_str(s);
        printf("\nStarting: %s\n", s);
        if (!find_bounds(s, &b.l, &b.r)) {
            return;
        }
        char* var = find_var(b.l, b.r);
        if (!var && !solve_arithmetic(s, &b)) {
            return;
        } else {
            // process_algebraic(s);
        }
    }
}
