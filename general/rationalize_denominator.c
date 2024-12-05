#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"
#include "../formatting/formatting.h"

static void find_bounds(char** l_bound, char** r_bound, const char* div_sign)
{
    *l_bound = *r_bound = NULL;
    if (*(div_sign + 1) != '(' || !isdigit(*(div_sign + 2))) {
        return;
    }
    char* pow_sign = extract_num_fwd((char[]){0}, div_sign + 2) + 1;
    if (*pow_sign != '^'
        || *(pow_sign + 1) != '('
        || !isdigit(*(pow_sign + 2))) {
        return;
    }
    char* exp_div_sign = extract_num_fwd((char[]){0}, pow_sign + 2) + 1;
    if (*exp_div_sign != '/' || !isdigit(*(exp_div_sign + 1))) {
        return;
    }
    *l_bound = (char*)(div_sign + 1);
    *r_bound = extract_num_fwd((char[]){0}, exp_div_sign + 1) + 1;
}

void rationalize_denominator(char* s)
{

    char* p = s;
    char* div_sign;
    char* l_bound, * r_bound;
    char den[STR_MAXLEN] = {0};
    char* p_den = den;
    size_t den_len;
    while (*p) {
        format_str(s);
        if (!(div_sign = strchr(p, '/'))) {
            return;
        }        
        find_bounds(&l_bound, &r_bound, div_sign);
        if (!l_bound || !r_bound) {
            p = div_sign + 1;
            continue;
        }
        memset(den, '\0', STR_MAXLEN);
        *p_den++ = '*';
        extract_bounded_str(p_den, l_bound, r_bound);
        if (!strchr(den, '^')) {
            p = div_sign + 1;
            continue;
        }
        strcat(den, ")");
        den_len = strlen(den);
        insert_str(s, l_bound - 1, den);
        insert_str(s, r_bound + den_len + 1, den);
        div_sign+=den_len;
        insert_str(s, div_sign + 1, "(");
        p = r_bound + den_len + 1;
        
    }
}
