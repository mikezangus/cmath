#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

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

static char* find_mult_1_start(const char* start, const char* min)
{
    int scale = 0;
    for (const char* p = start; p >= min; p--) {
        balance_chars(*p, &scale, '(', ')');
        if (scale == 0) {
            return (char*)p;
        }
    }
    return NULL;
}

void rationalize_denominator(char* s)
{
    char* p = s;
    char* div_sign;
    char* l_bound, * r_bound;
    char den[STR_MAXLEN] = {0};
    char* p_den = den;
    size_t den_len;
    printf("\n\n\nRationalizing denominator. Start:\n%s\n\n", s);
    while (*p && (div_sign = strchr(p, '/'))) {
        printf("Loop:\n%s\n\n", div_sign);      
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
        strcat(den, "))");
        den_len = strlen(den);
        insert_str(s, find_mult_1_start(div_sign++ - 1, s), "(");
        insert_str(s, l_bound, den);
        insert_str(s, div_sign + den_len + 1, "(");
        insert_str(s, r_bound += 3 + den_len + 1, den);
        p = r_bound + den_len;
        printf("Rationalized:\n%s\n", s);
    }
}
