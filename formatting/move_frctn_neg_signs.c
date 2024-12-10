#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../utils/utils.h"

static char* find_l_bound(const char* div_sign, const char* src)
{
    int scale = 0;
    for (const char* p = div_sign - 1; p > src; p--) {
        balance_chars(*p, &scale, '(', ')');
        if (scale == 0 && *(p - 1) == '(') {
            return (char*)p;
        }
    }
    return NULL;
}

static bool remove_double(char* l_bound, char* div_sign)
{
    if (*(l_bound) != '-' || *(div_sign + 1) != '-') {
        return false;
    }
    collapse_str(l_bound, l_bound);
    collapse_str(div_sign, div_sign);
    return true;
}

static bool move_to_numerator(char* src, char* l_bound, char* div_sign)
{
    if (*(div_sign + 1) != '-') {
        return false;
    }
    collapse_str(div_sign + 1, div_sign + 1);
    insert_str(src, l_bound, "-");
    return true;
}

static bool move_to_in_parens(char* src, char* l_bound)
{
    if (l_bound - 3 < src
        || *(l_bound - 1) != '('
        || *(l_bound - 2) != '-'
        || isdigit(*(l_bound - 3))) {
        return false;
    }
    collapse_str(l_bound - 2, l_bound - 2);
    insert_str(src, l_bound - 1, "-");
    return true;
}

bool move_frctn_neg_signs(char* s)
{
    bool formatted = false;
    char* p = s;
    char* div_sign;
    char* l_bound;
    while ((div_sign = strchr(p, '/'))
           && (l_bound = find_l_bound(div_sign, s))) {
        if (remove_double(l_bound, div_sign)
            || move_to_numerator(s, l_bound, div_sign)) {
            formatted = true;
            p = s;
        } else {
            p = div_sign + 1;
        }
    }
    return formatted;
}
