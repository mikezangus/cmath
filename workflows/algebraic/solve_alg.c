#include "../../main.h"
#include "../../general/general.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../utils/utils.h"
#include "algebraic.h"

void process_vars(char *op1, char *op2)
{
    if (var_exists(op1) || var_exists(op2)) {
        printf("Vars exist in either op1, or op2\n");
        parse_var(op1, &vars.op1n_var, &vars.op1n_exp);
        remove_vars(op1);

        parse_var(op2, &vars.op2n_var, &vars.op2n_exp);
        remove_vars(op2);

        printf("Parsed vars:\n  1: %c^%.1f\n  2: %c^%.1f\n", vars.op1n_var, vars.op1d_exp, vars.op2n_var, vars.op2n_exp);

        calculate_vars(eq.oprtr, vars.op1n_var, vars.op2n_var, vars.result_varn, vars.op1n_exp, vars.op2n_exp, &vars.result_expnd);
        convert_d_to_str(vars.result_expnd, vars.result_expns);
        create_var_str(vars.result_varn, vars.result_expns, vars.resultns);
    }
}

void solve_alg(char *s)
{
    printf("\n\nStart of solve loop: %s\n", s);
    
    find_bounds(s, &bounds.l, &bounds.r);
    parse_equation(s, bounds.l, bounds.r, eq.op1ns, eq.op1ds, &eq.oprtr, eq.op2ns, eq.op2ds);
    insert_denom(eq.op1ds, eq.op2ds);



    process_vars(eq.op1ns, eq.op2ns);

    printf("\nBase digits after parsing vars:\n%s/%s %c %s/%s\n", eq.op1ns, eq.op1ds, eq.oprtr, eq.op2ns, eq.op2ds);
    printf("Solved variables: %s\n", vars.resultns);

    convert_str_to_d(eq.op1ns, &eq.op1nd);
    convert_str_to_d(eq.op2ns, &eq.op2nd);

    if (*eq.op1ds != '\0' && *eq.op2ds != '\0') {
        process_vars(eq.op1ds, eq.op2ds);
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

    strcat(eq.resultns, vars.resultns);
    strcat(eq.resultds, vars.resultds);
    printf("After string cat: %s/%s\n", eq.resultns, eq.resultds);

    create_result_str(eq.resultns, eq.resultds, eq.results);
    insert_result(s, bounds.l, bounds.r, eq.results);
    printf("\n%s\n", s);
}


/*
2x^2+2x^2

*/
