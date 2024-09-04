#include <stdio.h>
#include "./arithmetic.h"
#include "../../main.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

struct Bounds bounds;

void solve(char *s)
{
    char dashes[] = "-------------------------";
    printf("\n%s\nSolving for:\n%s\n", dashes, s);
    find_bounds(s, &bounds.l, &bounds.r);
    parse_equation(s, bounds.l, bounds.r, eq.op1ns, eq.op1ds, &eq.oprtr, eq.op2ns, eq.op2ds);
    insert_denom(eq.op1ds, eq.op2ds);
    convert_str_to_d(eq.op1ns, &eq.op1nd);
    convert_str_to_d(eq.op2ns, &eq.op2nd);
    if (*eq.op1ds != '\0' && *eq.op2ds != '\0') {
        convert_str_to_d(eq.op1ds, &eq.op1dd);
        convert_str_to_d(eq.op2ds, &eq.op2dd);
        reduce_fraction(&eq.op1nd, &eq.op1dd);
        reduce_fraction(&eq.op2nd, &eq.op2dd);
        equate_denoms(&eq.op1nd, &eq.op1dd, &eq.op2nd, &eq.op2dd);
        eq.resultdd = eq.op1dd;
    }
    calculate_result(eq.op1nd, eq.oprtr, eq.op2nd, &eq.resultnd);
    if (eq.resultdd != 0.0) {
        reduce_fraction(&eq.resultnd, &eq.resultdd);
        convert_d_to_str(eq.resultdd, eq.resultds);
    }
    convert_d_to_str(eq.resultnd, eq.resultns);
    create_result_str(eq.resultns, eq.resultds, eq.results);
    insert_result(s, bounds.l, bounds.r, eq.results);
    printf("%s\n", dashes);
}
