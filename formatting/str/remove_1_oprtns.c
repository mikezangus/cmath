#include <ctype.h>
#include <stdio.h>
#include "../../utils/utils.h"

static void remove_mult_1s(char* s)
{
    char* p_oprtr = s;
    while ((p_oprtr = find_char('*', p_oprtr, NULL)) != NULL) {
        if ((p_oprtr - 1 < s)
            || *(p_oprtr - 1) != '1'
            || ((p_oprtr - 2 >= s) && isdigit(*(p_oprtr - 2)))) {
            p_oprtr++;
            continue;
        }
        collapse_str(p_oprtr - 1, p_oprtr);
    }
}

static void remove_div_1s(char* s)
{
    char* p_oprtr = s;
    while ((p_oprtr = find_char('/', p_oprtr, NULL)) != NULL) {
        if (!*(p_oprtr + 1)
            || *(p_oprtr + 1) != '1'
            || (*(p_oprtr + 2) && isdigit(*(p_oprtr + 2)))) {
            p_oprtr++;
            continue;
        }
        collapse_str(p_oprtr, p_oprtr + 1);
    }
}

void remove_1_oprtns(char* s)
{
    remove_mult_1s(s);
    remove_div_1s(s);
}
