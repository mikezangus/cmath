#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "../utils/utils.h"

static bool remove_mult_1s(char* s)
{
    bool formatted = false;
    char* mult_sign = s + 2;
    while ((mult_sign = find_char('*', mult_sign, NULL))) {
        if (*(mult_sign - 1) != '1' || isdigit(*(mult_sign - 2))) {
            mult_sign++;
            continue;
        }
        collapse_str(mult_sign - 1, mult_sign);
        formatted = true;
    }
    return formatted;
}

static bool remove_div_1s(char* s)
{
    bool formatted = false;
    char* div_sign = s;
    while ((div_sign = find_char('/', div_sign, NULL))) {
        if (!*(div_sign + 1)
            || *(div_sign + 1) != '1'
            || (*(div_sign + 2) && isdigit(*(div_sign + 2)))) {
            div_sign++;
            continue;
        }
        collapse_str(div_sign, div_sign + 1);
        formatted = true;
    }
    return formatted;
}

bool remove_1_oprtns(char* s)
{
    return remove_mult_1s(s) | remove_div_1s(s);
}
