#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "../../main.h"
#include "../../formatting/formatting.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

static char* find_pow_sign_l(const char* mult_sign, const char* min)
{
    int scale = 0;
    for (const char* p = mult_sign - 2; p > min; p--) {
        balance_chars(*p, &scale, '(', ')');
        if (scale > 0) {
            break;
        }
        if (scale == 0 && is_oprtr(*p)) {
            return *p == '^' ? (char*)p : NULL;
        }
    }
    return NULL;
}

static char* find_pow_sign_r(const char* mult_sign)
{
    int scale = 0;
    for (const char* p = mult_sign + 2; *p; p++) {
        balance_chars(*p, &scale, '(', ')');
        if (scale == 0 && is_oprtr(*p)) {
            return *p == '^' ? (char*)p : NULL;
        }
    }
    return NULL;
}

static void extract_base(char* dst, const char* pow_sign, const char* min)
{
    const char* p = pow_sign > min + 1 && *(pow_sign - 1) == ')'
        ? pow_sign - 2
        : pow_sign - 1;
    extract_num_bwd(dst, p, min);
}

static char* extract_exp(char* dst, const char* pow_sign)
{
    const char* p = *(pow_sign + 1) == '(' ? pow_sign + 2 : pow_sign + 1;
    while (*p && !is_paren(*p)) {
        *dst++ = *p++;
    }
    *dst = '\0';
    return (char*)(p - 1);
}

static void calculate_exp(char* dst, const char* src1, const char* src2)
{
    double n1 = str_to_d(src1);
    double d1 = NAN;
    double n2 = str_to_d(src2);
    double d2 = NAN;
    double nr = 0.0;
    double dr = NAN;
    const char* div1 = strchr(src1, '/');
    const char* div2 = strchr(src2, '/');
    if (div1) {
        d1 = str_to_d(div1 + 1);
    }
    if (div2) {
        d2 = str_to_d(div2 + 1);
    }
    equate_denoms(&n1, &d1, &n2, &d2);
    nr = n1 + n2;
    dr = d1;
    reduce_frctn(&nr, &dr);
    d_to_str(dst, nr);
    if (dr == 1.0) {
        return;
    }
    *(dst + strlen(dst)) = '/';
    d_to_str(dst + strlen(dst), dr);
}

void apply_prdct_of_pows_rule(char* s)
{
    char* p = s + 2;
    char* mult_sign;
    char* pow_sign_l;
    char* pow_sign_r;
    char b1[STR_MAXLEN] = {0};
    char b2[STR_MAXLEN] = {0};
    char e1[STR_MAXLEN] = {0};
    char e2[STR_MAXLEN] = {0};
    char e[STR_MAXLEN] = {0};
    char* collapse_l;
    char* collapse_r;
    while (*p && (mult_sign = strchr(p, '*'))) {
        if (*(mult_sign + 1) != '('
            || !isdigit(*(mult_sign + 2))
            || *(mult_sign - 1) != ')'
            || !(pow_sign_l = find_pow_sign_l(mult_sign, s))
            || !(pow_sign_r = find_pow_sign_r(mult_sign))) {
            p = mult_sign + 1;
            continue;
        }
        extract_base(b1, pow_sign_l, s);
        extract_base(b2, pow_sign_r, s);
        if (strcmp(b1, b2)) {
            p = pow_sign_r + 1;
            continue;
        }
        extract_exp(e1, pow_sign_l);
        collapse_l = *(pow_sign_l + 1) == '(' ? pow_sign_l + 2 : pow_sign_l + 1;
        collapse_r = extract_exp(e2, pow_sign_r);
        calculate_exp(e, e1, e2);
        collapse_str(collapse_l, collapse_r);
        insert_str(s, collapse_l, e);
        format_str(s);
    }
}
