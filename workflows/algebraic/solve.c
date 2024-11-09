#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "algebraic.h"
#include "../../main.h"
#include "../../bounding/bounding.h"
#include "../../formatting/formatting.h"
#include "../../utils/utils.h"
#include "../../workflows/arithmetic/arithmetic.h"

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
    printf("\nEntering solve_algebraic(). Shedding everything except input:"
           "\n  %s\n", s);
    isolate_num_oprtn(s);
    isolate_var_base(s);
    strip_equation(s);
    return false;
}
