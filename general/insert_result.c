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

void insert_result(char *destination, int l_bound, int r_bound, char *insertion)
{
    if (check_if_between_parens(l_bound, r_bound)) {
        l_bound--;
        r_bound++;
    }
    collapse_str(input, l_bound, r_bound);
    expand_str(input, insertion, l_bound);
    insert_str(input, insertion, l_bound);
}
