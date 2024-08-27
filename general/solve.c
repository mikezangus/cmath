
#include <stdio.h>
#include "general.h"
#include "../main.h"
#include "../workflows/arithmetic/arithmetic.h"
#include "../workflows/algebraic/algebraic.h"


static void init(void)
{
    parens.l = parens.r = -1;
    bounds.l = bounds.r = -1;
    sw.parens_exist = 0;
}

void sequence(int l_bound, int r_bound)
{
    parse_equation(l_bound, r_bound);
    convert_str_to_d();
    calculate_result();
    convert_d_to_str();
    insert_result(l_bound, r_bound);
}

void solve(void)
{
    printf("\nStarting equation: %s\n", input);
    init();
    if ((sw.parens_exist = check_parens_exist())) {
        find_nearest_parens();
    }
    if (sw.arithmetic) {
        find_bounds_ari();
        sequence(bounds.l, bounds.r);
    } else if (sw.alg_1var) {
        find_bounds_alg('l');
        sequence(bounds.l, bounds.r);
        find_bounds_alg('r');
        sequence(bounds.l, bounds.r);
    }
    // find_bounds();

}
