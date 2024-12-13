#include <ctype.h>
#include "../main.h"
#include "../utils/utils.h"

static void remove_doubles(char* s, char* div_oprtr,
                           char* l_bound, char** r_bound)
{
    if (*(l_bound) != '-' || *(div_oprtr + 1) != '-') {
        return;
    }
    collapse_str(l_bound, l_bound);
    collapse_str(div_oprtr, div_oprtr);
    (*r_bound)-=2;
}

static void move_to_numerator(char* s, char** div_oprtr, char* l_bound)
{
    char* neg_sign = *div_oprtr + 1;
    if (*neg_sign != '-') {
        return;
    }
    collapse_str(neg_sign, neg_sign);
    insert_str(s, l_bound, "-");
    (*div_oprtr)++;
}

static void move_to_inside_parens(char* s, char** l_bound)
{
    if (*l_bound - 2 < s) {
        return;
    }
    char* neg_sign = *l_bound - 2;
    if (*neg_sign != '-'
        || *(neg_sign + 1) != '('
        || neg_sign + 1 != *l_bound - 1
        || neg_sign > s && isdigit(*(neg_sign - 1))) {
        return;
    }
    (*l_bound)--;
    collapse_str(neg_sign, neg_sign);
    insert_str(s, *l_bound, "-");
}

void format_frctn_neg_signs(char* s, char* div_sign,
                            char** l_bound, char** r_bound)
{
    char* div_oprtr = find_char('/', *l_bound + 1, *r_bound - 1);
    if (!div_oprtr) {
        return;
    }
    remove_doubles(s, div_oprtr, *l_bound, r_bound);
    move_to_numerator(s, &div_oprtr, *l_bound);
    move_to_inside_parens(s, l_bound);
}
