#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"
#include "../formatting/formatting.h"

static char* find_exp_sign(char* s)
{
    char* e = strchr(s, '^');
    if (!e || e - 5 < s) {
        return NULL;
    }
    return e;
}

static char* find_div_sign(char* s, char* exp_sign)
{
    if (*(exp_sign - 1) != ')') {
        return NULL;
    }
    char* d = exp_sign - 2;
    while (d > s && is_num(d, NULL)) {
        d--;
    }
    if (d == s || *d != '/') {
        return NULL;
    }
    return d;
}

static char* extract_exp(char* dst, char* src_exp_sign)
{
    int scale = 0;
    char* p = src_exp_sign;
    for (; *p; p++, dst++) {
        *dst = *p;
        balance_chars(*p, &scale, '(', ')');
        if (p > src_exp_sign && scale == 0) {
            return p;
        }
    }
    return p;
}

static void move_exp(char* dst, char* src,
                     char* div_sign, char* exp_sign, char* exp_end)
{
    collapse_str(exp_sign, exp_end);
    insert_str(dst, src, div_sign);
    insert_str(dst, src, exp_sign - 1 + strlen(src));
    insert_parens(dst);
    remove_unneeded_parens(dst);
}

void appy_exp_rule_to_frctns(char* s)
{
    char* exp_sign = find_exp_sign(s);
    if (!exp_sign) {
        return;
    }
    char* div_sign = find_div_sign(s, exp_sign);
    if (!div_sign) {
        return;
    }
    char exp[STR_MAXLEN] = {0};
    char* exp_end = extract_exp(exp, exp_sign);
    move_exp(s, exp, div_sign, exp_sign, exp_end);
}
