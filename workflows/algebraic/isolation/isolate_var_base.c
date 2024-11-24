#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_base_oprtn(char* dst,
                               char** start, char** end,
                               const char* src, const char* eq_sign)
{
    char* p_dst = dst;
    for (const char* p_src = src, * var; p_src < eq_sign; p_src = var + 1) {
        var = find_var(p_src, strchr(src, '=') - 1);
        if (!var || var - 1 < src) {
            return false;
        }
        if (!isdigit(*(var - 1)) || get_paren_depth(var, eq_sign - 1) != -1) {
            continue;
        }
        *p_dst++ = '/';
        *start = extract_num_bwd(p_dst, var - 1, src);
        *end = (char*)(var - 1);
        return true;
    }
    return false;
}

void isolate_var_base(char* s, Bounds* b)
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
        if (!extract_base_oprtn(oprtn, &start, &end, s, eq_sign)
            || *oprtn == '\0') {
            return;
        }
        collapse_str(start, end);
        insert_str(s, oprtn, s + strlen(s));
        if (!solve_arithmetic(strchr(s, '=') + 1, b)) {
            return;
        }
    }
}
