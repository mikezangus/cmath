#include <ctype.h>
#include "../main.h"
#include "../utils/utils.h"

static void remove_double_neg_signs(char* s, char* div_oprtr, Bounds* b)
{
    if (*(b->l) != '-' || *(div_oprtr + 1) != '-') {
        return;
    }
    collapse_str(b->l, b->l);
    collapse_str(div_oprtr, div_oprtr);
    b->r-=2;
}

static void move_to_numerator(char* s, char** div_oprtr, Bounds* b)
{
    char* neg_sign = *div_oprtr + 1;
    if (*neg_sign != '-') {
        return;
    }
    collapse_str(neg_sign, neg_sign);
    insert_str(s, b->l, "-");
    (*div_oprtr)++;
}

static void move_to_inside_parens(char* s, Bounds* b)
{
    if (b->l - 2 < s) {
        return;
    }
    char* neg_sign = b->l - 2;
    if (*neg_sign != '-'
        || *(neg_sign + 1) != '('
        || neg_sign + 1 != b->l - 1
        || neg_sign > s && isdigit(*(neg_sign - 1))) {
        return;
    }
    b->l--;
    collapse_str(neg_sign, neg_sign);
    insert_str(s, b->l, "-");
}

void format_frctn_neg_signs(char* s, char* div_sign, Bounds* b)
{
    char* div_oprtr = find_char('/', b->l + 1, b->r - 1);
    if (!div_oprtr) {
        return;
    }
    remove_double_neg_signs(s, div_oprtr, b);
    move_to_numerator(s, &div_oprtr, b);
    move_to_inside_parens(s, b);
}
