#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../formatting/formatting.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_base_oprtn(char* dst,
                               char** start, char** end,
                               const char* src, const char* eq_sign)
{
    for (const char* p_src = src, * var; p_src < eq_sign; p_src = var + 1) {
        var = find_var(p_src, strchr(src, '=') - 1);
        if (!var || var - 1 < src) {
            return false;
        }
        if (!isdigit(*(var - 1)) || get_paren_depth(var, eq_sign - 1) != -1) {
            continue;
        }
        *dst++ = '/';
        *start = extract_num(dst, var - 1, src, -1);
        *end = (char*)(var - 1);
        return true;
    }
    return false;
}

void isolate_var_base(char* s)
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
        if (!extract_base_oprtn(oprtn, &extract_l, &extract_r, s, eq_sign)
            || *oprtn == '\0') {
            return;
        }
        print_bounded_str(extract_l, extract_r);
        collapse_str(extract_l, extract_r);
        insert_str(s, s + strlen(s), oprtn);
        format_str(s);
        l_bound = r_bound = NULL;
        if (!solve_arithmetic(strchr(s, '=') + 1, s, &l_bound, &r_bound)) {
            return;
        }
    }
}
