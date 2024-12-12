#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../formatting/formatting.h"
#include "../../../utils/utils.h"
#include "../../../workflows/arithmetic/arithmetic.h"

static bool extract_leading_sum_oprtn(char* dst, char** start, char** end,
                                      const char* src)
{
    if (isdigit(*src)) {
        *dst++ = '-';
        *start = (char*)src;
        *end = extract_num(dst, src, src, 1);
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
    for (const char* p_src = src, * oprtr; p_src < eq_sign; p_src = oprtr + 1) {
        if (!(oprtr = find_oprtr(p_src, eq_sign - 1))) {
            return false;
        }
        if (get_paren_depth(oprtr, eq_sign - 1) != 0) {
            continue;
        }
        *dst++ = invert_oprtr(*oprtr);
        *start = (char*)oprtr;
        *end = extract_num(dst, oprtr + 1, src, 1);
        return true;
    }
    return false;
}

void isolate_num_oprtn(char* s)
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
        if (!extract_num_oprtn(oprtn, &extract_l, &extract_r, s, eq_sign)
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
