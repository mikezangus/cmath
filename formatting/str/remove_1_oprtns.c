#include <ctype.h>
#include <stdio.h>
#include "../../utils/utils.h"

static void remove_mult_1s(char* s)
{
    char* mult_sign = s + 2;
    while ((mult_sign = find_char('*', mult_sign, NULL))) {
        if (*(mult_sign - 1) != '1' || isdigit(*(mult_sign - 2))) {
            mult_sign++;
            continue;
        }
        collapse_str(mult_sign - 1, mult_sign);
    }
}

static void remove_div_1s(char* s)
{
    char* div_sign = s;
    while ((div_sign = find_char('/', div_sign, NULL))) {
        if (!*(div_sign + 1)
            || *(div_sign + 1) != '1'
            || (*(div_sign + 2) && isdigit(*(div_sign + 2)))) {
            div_sign++;
            continue;
        }
        collapse_str(div_sign, div_sign + 1);
    }
}

void remove_1_oprtns(char* s)
{
    remove_mult_1s(s);
    remove_div_1s(s);
}
