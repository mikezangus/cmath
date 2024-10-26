#include <ctype.h>
#include <stdio.h>
#include "../../utils/utils.h"

static void insert_mult1(char* s, char** var)
{
    if (*var == s) {
        ;;
    } else if (*(*var - 1) == '*' || isdigit(*(*var - 1))) {
        return;
    }
    insert_str(s, "1", *var);
    (*var)++;
}

static void insert_exp1(char* s, char* var)
{
    if (*(var + 1) == '^' && isdigit(*(var + 2))) {
        return;
    }
    insert_str(s, "^1", var + 1);
}

void format_vars(char* s)
{
    char* p = s;
    while (*p) {
        char* var = find_var(p, NULL);
        if (!var) {
            return;
        }
        insert_mult1(s, &var);
        insert_exp1(s, var);
        p = var + 1;
    }
}
