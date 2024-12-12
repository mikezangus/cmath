#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../formatting/formatting.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_var_exp_oprtn(char* dst,
                                  char** start, char** end,
                                  const char* src, const char* eq_sign)
{
    for (const char* p_src = src, * var; p_src < eq_sign; p_src = var + 1) {
        if (!(var = find_var(p_src, eq_sign - 1))) {
            return false;
        }
        if (*(var + 1) != '^'
            || !isdigit(*(var + 2))
            || (*(var + 2) == 1 && isdigit(*(var + 3)))
            || get_paren_depth(var + 2, eq_sign) != -1) {
            continue;
        }
        strcpy(dst, "^(1/");
        *start = (char*)(var + 1);
        *end = extract_num(dst + 4, var + 2, src, 1);
        *(dst + strlen(dst)) = ')';
        return true;
    }
    return false;
}

void isolate_var_exp(char* s)
{
    const char* eq_sign;
    char oprtn[STR_MAXLEN];
    char* extract_l;
    char* extract_r;
    char* l_bound;
    char* r_bound;
    while (true) {
        if (!(eq_sign = strchr(s, '='))) {
            return;
        }
        memset(oprtn, '\0', STR_MAXLEN);
        if (!extract_var_exp_oprtn(oprtn, &extract_l, &extract_r, s, eq_sign)
            || *oprtn == '\0') {
            return;
        }
        collapse_str(extract_l, extract_r);
        insert_str(s, s + strlen(s), oprtn);
        format_str(s);
        l_bound = r_bound = NULL;
        if (!solve_arithmetic(strchr(s, '=') + 1, s, &l_bound, &r_bound)) {
            return;
        }
    }
}