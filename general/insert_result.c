#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

#include <stdio.h>

static int check_if_between_parens(void)
{
    if (input[bounds.l - 1] == '(' && input[bounds.r + 1] == ')') {
        return 1;
    }
    return 0;
}

void insert_result(void)
{
    int start = bounds.l;
    int end = bounds.r;
    if (check_if_between_parens()) {
        start--;
        end++;
    }
    collapse_str(input, start, end);
    expand_str(input, eq.results, start);
    insert_str(input, eq.results, start);
}
