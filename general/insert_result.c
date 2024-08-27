#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

#include <stdio.h>

static int check_if_between_parens(int start, int end)
{
    if (input[start - 1] == '(' && input[end + 1] == ')') {
        return 1;
    }
    return 0;
}

void insert_result(int start, int end)
{
    if (check_if_between_parens(start, end)) {
        start--;
        end++;
    }
    collapse_str(input, start, end);
    expand_str(input, eq.results, start);
    insert_str(input, eq.results, start);
}
