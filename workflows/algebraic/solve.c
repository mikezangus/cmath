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


static bool extract_num_oprtn(char* dst, char* src)
{
    char* p_dst = dst;
    if (isdigit(*src)) {
        *p_dst++ = '-';
        extract_num_fwd(p_dst, src + 1);
        return true;
    }
    for (char* p_src = src, * eq_sign = NULL, * oprtr = NULL;
         *p_src && *p_src != '=';
         p_src = oprtr + 1) {
        if (!(eq_sign = strchr(p_src, '='))
            || !(oprtr = find_oprtr(p_src, eq_sign - 1))) {
            break;
        }
        if (get_paren_depth(oprtr, eq_sign - 1) != 0) {
            continue;
        }
        memset(dst, '\0', STR_MAXLEN);
        *p_dst++ = invert_oprtr(*oprtr);
        collapse_str(oprtr, extract_num_fwd(p_dst, oprtr + 1));
        insert_str(src, dst, src + strlen(src));
        return true;
    }
    return false;
}


static void strip_exp1(char* var)
{
    if (var + 3 <= var + strlen(var)
        && *(var + 1) == '^'
        && *(var + 2) == '1'
        && !isdigit(*(var + 2))) {
        collapse_str(var + 1, var + 2);
    }
}


static void strip_mult1(char* var, char* s)
{
    if (var - 2 >= s && *(var - 1) == '1' && !isdigit(*(var - 2))) {
        collapse_str(var - 1, var - 1);
    }
}


static void strip_vars(char* s)
{
    char* var = find_var(s, NULL);
    if (var) {
        strip_exp1(var);
        strip_mult1(var, s);
    }
}


bool solve_algebraic(char* s)
{
    printf("\nEntering solve_algebraic(). Shedding everything except input:"
           "\n  %s\n", s);
    char insert[100] = {0};
    if (!extract_num_oprtn(insert, s)) {
        return false;
    }
    strip_vars(s);
    printf("New string: %s\n", s);
    enter_workflow(strchr(s, '=') + 1);

    return false;
}
