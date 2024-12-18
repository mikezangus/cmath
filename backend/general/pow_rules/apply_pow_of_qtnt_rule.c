#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../main.h"
#include "../../utils/utils.h"

static char* find_div_sign(const char* start, const char* src)
{
    char* den_start = walk_num_bwd(start, src);
    if (den_start - 1 < src || *(den_start - 1) != '/') {
        return NULL;
    }
    return den_start - 1;
}

static char* extract_exp(char* dst, char* src)
{
    bool parens = false;
    char* p = src;
    while (*p && *p != ')') {
        if (*p == '(') {
            parens = true;
        }
        *dst++ = *p++;
    }
    if (parens) {
        *dst++ = *p++;
    }
    *dst++ = ')';
    *dst = '\0';
    collapse_str(src, p);
    return (*p && p > src) ? (char*)(p - 1) : NULL;
}

void apply_pow_of_qtnt_rule(char* s)
{
    char* p = s;
    char* pow_sign;
    char* div_sign;
    char exp[STR_MAXLEN] = {0};
    size_t exp_len;
    while (*p) {
        if (!(pow_sign = strchr(p, '^'))) {
            return;
        }
        if (pow_sign - 6 < s
            || *(pow_sign - 1) != ')'
            || !isdigit(*(pow_sign - 2))
            || !(div_sign = find_div_sign(pow_sign - 2, s))) {
            p = pow_sign + 1;
            continue;
        }
        memset(exp, '\0', STR_MAXLEN);
        char* exp_end = extract_exp(exp, pow_sign);
        if (!*exp || !exp_end) {
            p = pow_sign + 1;
            continue;
        }
        exp_len = strlen(exp);
        insert_str(s, div_sign, exp);
        insert_str(s, div_sign + exp_len + 1, "(");
        insert_str(s, pow_sign + exp_len, exp);
    }
}
