#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algebraic.h"
#include "../../main.h"
#include "../../bounding/bounding.h"
#include "../../formatting/formatting.h"
#include "../../utils/utils.h"
#include "../../workflows/arithmetic/arithmetic.h"

#include "../../general/general.h"

static void strip_exp1(char* var)
{
    if (var + 3 <= var + strlen(var)
        && *(var + 1) == '^'
        && *(var + 2) == '1'
        && !isdigit(*(var + 3))) {
        collapse_str(var + 1, var + 2);
    }
}

static void strip_mult1(char* var, char* s)
{
    if (var - 2 >= s && *(var - 1) == '1' && !isdigit(*(var - 2))) {
        collapse_str(var - 1, var - 1);
    }
}

static void strip_equation(char* s)
{
    char* var = find_var(s, NULL);
    if (var) {
        strip_exp1(var);
        strip_mult1(var, s);
    }
    if (*s == '+') {
        collapse_str(s, s);
    }
}

bool solve_algebraic(char* s)
{
    printf("\n\n\nEntering solve_algebraic(). Shedding everything except input:"
           "\n  %s\n", s);
    printf("\n\nBefore isolating: %s\n", s);
    isolate(s);
    format_str(s);
    printf("\n\nAfter isolating:  %s\n\n", s);


    
    apply_pow_of_qtnt_rule(s);
    printf("\nApplied power of quotient rule:\n%s\n", s);
    char* l_bound;
    char* r_bound;
    l_bound = r_bound = NULL;
    solve_arithmetic(s, s, &l_bound, &r_bound);
    rationalize_denominator(s);
    printf("\nRationalized:\n%s\n", s);

    apply_prdct_of_pows_rule(s);
    printf("\nApplied product of powers rule:\n%s\n", s);
    

    while (true) {
        format_str(s);
        printf("After formatting: %s\n", s);
        if (!find_bounds(s, &l_bound, &r_bound)) {
            break;
        }
        if (!solve_arithmetic(s, s, &l_bound, &r_bound)) {
            break;
        }
        printf("Before second format: %s\n", s);
        format_str(s);
        printf("After second format:  %s\n", s);
    }
    strip_equation(s);
    return false;
}
