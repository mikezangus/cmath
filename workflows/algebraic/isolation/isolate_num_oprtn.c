#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_leading_sum_oprtn(char* dst, char** start, char** end,
                                      const char* src)
{
    if (isdigit(*src)) {
        *dst++ = '-';
        *start = (char*)src;
        *end = extract_num_fwd(dst, src);
        return true;
    }
    return false;
}

static bool extract_num_oprtn(char* dst, char** start, char** end,
                              const char* src, const char* eq_sign)
{
    if (extract_leading_sum_oprtn(dst, start, end, src)) {
        return true;
    }
    char* p_dst = dst;
    const char* oprtr;
    for (const char* p_src = src; p_src < eq_sign; p_src = oprtr + 1) {
        if (!(oprtr = find_oprtr(p_src, eq_sign - 1))) {
            return false;
        }
        if (get_paren_depth(oprtr, eq_sign - 1) != 0) {
            continue;
        }
        *p_dst++ = invert_oprtr(*oprtr);
        *start = (char*)oprtr;
        *end = extract_num_fwd(p_dst, oprtr + 1);
        return true;
    }
    return false;
}

void isolate_num_oprtn(char* s, Bounds* b)
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
        if (!extract_num_oprtn(oprtn, &start, &end, s, eq_sign)
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
