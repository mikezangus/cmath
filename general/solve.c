
#include <stdio.h>
#include "general.h"
#include "../main.h"


static void init(void)
{
    parens.l = parens.r = -1;
    bounds.l = bounds.r = -1;
    sw.parens_exist = 0;
}

void solve(void)
{
    printf("\nStarting equation: %s\n", input);
    init();
    if ((sw.parens_exist = check_parens_exist(input))) {
        find_nearest_parens(input);
    }
    find_bounds();
    parse_equation();
    convert_str_to_d();
    calculate_result();
    convert_d_to_str();
    insert_result(input);
}
