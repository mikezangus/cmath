#include <ctype.h>
#include <stdio.h>
#include "../../utils/utils.h"

static void remove_mult_sign(char* s, char** var)
{
    if (*var - 2 < s) {
        return;
    }
    if (*(*var - 1) != '*' || !isdigit(*(*var - 2))) {
        return;
    }
    collapse_str(*var - 1, *var - 1);
    (*var)--;
}

static void insert_base1(char* s, char** var)
{
    if (*var == s) {
        ;;
    } else if (*(*var - 1) == '*' || isdigit(*(*var - 1))) {
        return;
    }
    insert_str(s, *var, "1");
    (*var)++;
}

static void insert_exp1(char* s, char* var)
{
    if (*(var + 1) == '^' && isdigit(*(var + 2))) {
        return;
    }
    insert_str(s, var + 1, "^1");
}

void format_vars(char* s)
{
    const char* p = s;
    while (*p) {
        char* var = find_var(p, NULL);
        if (!var) {
            return;
        }
        remove_mult_sign(s, &var);
        insert_base1(s, &var);
        insert_exp1(s, var);
        p = var + 1;
    }
}
