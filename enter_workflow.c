#include <stdbool.h>
#include <stdio.h>
#include "main.h"
#include "bounding/bounding.h"
#include "formatting/formatting.h"
#include "verifications/verifications.h"
#include "utils/utils.h"
#include "workflows/algebraic/algebraic.h"
#include "workflows/arithmetic/arithmetic.h"

Bounds b;

void enter_workflow(char* s)
{
    while (verify(s)) {
    // for (int i = 0; i < 6; i++) {
        format_parens(s);
        convert_neg_signs(s);
        printf("%s\nStarting: %s\n", DASHES, s);
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
    format_parens(s);
}
