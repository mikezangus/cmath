#include <string.h>
#include "../utils/utils.h"

static void check_between_parens(char *s, int *l_bound, int *r_bound)
{
    if (s[*l_bound - 1] == '(' && s[*r_bound + 1] == ')') {
        (*l_bound)--;
        (*r_bound)++;
    }
}

static void insert_add(char *destination, int *i_insert, char *insertion)
{
    if (!is_oprtr(destination[*i_insert]) && (destination[*(i_insert) - 1] != '=') && !is_oprtr(*insertion)) {
        insert_str(destination, "+", *i_insert);
        (*i_insert)++;
    }
}

void insert_result(char *destination, int l_bound, int r_bound, char *insertion, int sw_alg)
{
    check_between_parens(destination, &l_bound, &r_bound);
    collapse_str(destination, l_bound, r_bound);
    if (sw_alg) {
        insert_add(destination, &l_bound, insertion);
    }
    insert_str(destination, insertion, l_bound);
}
