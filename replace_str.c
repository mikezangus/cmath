#include <string.h>
#include "main.h"
#include "./utils/utils.h"

#include <stdio.h>

static int check_if_between_parens(char *s)
{
    if (s[bounds.l - 1] == '(' && s[bounds.r + 1] == ')') {
        return 1;
    }
    return 0;
}

void replace_str(char *s)
{
    int start = bounds.l;
    int end = bounds.r;
    if (check_if_between_parens(s)) {
        start--;
        end++;
    }
    collapse_str(s, start, end);
    expand_str(s, eq.results, start);
    insert_str(s, eq.results, start);
}
