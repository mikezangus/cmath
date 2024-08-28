
#include <stdio.h>
#include "general.h"
#include "../main.h"
#include "../workflows/arithmetic/arithmetic.h"
#include "../workflows/algebraic/algebraic.h"
#include "../utils/utils.h"

static void init(void)
{
    init_eq();
    parens.l = parens.r = -1;
    bounds.l = bounds.r = -1;
    sw.parens_exist = 0;
}

void sequence(int l_bound, int r_bound)
{
    parse_equation(l_bound, r_bound);
    insert_denom();
    convert_str_to_d(eq.op1ns, &(eq.op1nd));
    convert_str_to_d(eq.op2ns, &(eq.op2nd));
    if (*(eq.op1ds) != '\0' && *(eq.op2ds) != '\0') {
        convert_str_to_d(eq.op1ds, &(eq.op1dd));
        convert_str_to_d(eq.op2ds, &(eq.op2dd));
        equate_denoms(eq.op1nd, eq.op1dd, eq.op2nd, eq.op2dd);
        eq.resultdd = eq.op1dd;
    }
    calculate_result(eq.op1nd, eq.oprtr, eq.op2nd, &eq.resultnd);
    if (eq.resultdd != 0.0) {
        reduce_fraction(&(eq.resultnd), &(eq.resultdd));
        convert_d_to_str(eq.resultdd, eq.resultds);
    }
    convert_d_to_str(eq.resultnd, eq.resultns);
    create_result_str(eq.resultns, eq.resultds, eq.results);
    insert_result(input, l_bound, r_bound, eq.results);
}

void solve(void)
{
    printf("\n\n\nStarting equation: %s\n", input);
    init();
    if ((sw.parens_exist = check_parens_exist())) {
        find_nearest_parens();
    }
    if (sw.arithmetic) {
        find_bounds_ari();
        print_str("", input);
        printf("Bounds - L: %d | R: %d\n", bounds.l, bounds.r);
        sequence(bounds.l, bounds.r);
    }
    // else if (sw.alg_1var) {
    //     find_bounds_alg('l');
    //     sequence(bounds.l, bounds.r);
    //     find_bounds_alg('r');
    //     sequence(bounds.l, bounds.r);
    // }
    // find_bounds();

}
