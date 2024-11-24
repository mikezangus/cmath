#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_var_exp_oprtn(char* dst,
                                  char** start, char** end,
                                  const char* src, const char* eq_sign)
{
    char* p_dst = dst;
    char* var;
    for (const char* p_src = src; p_src < eq_sign; p_src = var + 1) {
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
        p_dst = dst + 4;
        *start = (char*)(var + 1);
        *end = extract_num_fwd(p_dst, var + 2);
        *(p_dst + strlen(p_dst)) = ')';
        return true;
    }
    return false;
}

void isolate_var_exp(char* s, Bounds* b)
{
    const char* eq_sign;
    char oprtn[STR_MAXLEN];
    char* start, * end;
    while (true) {
        if (!(eq_sign = strchr(s, '='))) {
            return;
        }
        b->l = b->r = NULL;
        memset(oprtn, '\0', STR_MAXLEN);
        if (!extract_var_exp_oprtn(oprtn, &start, &end, s, eq_sign)
            || *oprtn == '\0') {
            return;
        }
        printf("Extract: %s\n", oprtn);
        collapse_str(start, end);
        insert_str(s, oprtn, s + strlen(s));
        printf("New string: %s\n", s);
        if (!solve_arithmetic(strchr(s, '=') + 1, b)) {
            return;
        }
    }
}