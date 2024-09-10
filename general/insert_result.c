#include <string.h>
#include "../utils/utils.h"

static void check_between_parens(char* s, char* l_bound, char* r_bound)
{
    if (*(l_bound - 1) == '(' && *(r_bound + 1) == ')') {
        l_bound--;
        r_bound++;
    }
}

void insert_result(char* destination, int l_bound, int r_bound, char* insertion)
{
    // check_between_parens(destination, &l_bound, &r_bound);
    // collapse_str(destination, l_bound, r_bound);
    // insert_str(destination, insertion, l_bound);
    return;
}
