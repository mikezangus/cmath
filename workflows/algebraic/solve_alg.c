#include "../../main.h"
#include "../../general/general.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../utils/utils.h"
#include "algebraic.h"

static void init_vars(void)
{
    vars.op1n_var = vars.op1d_var = vars.op2n_var = vars.op2d_var = '\0';
    vars.op1n_var_exp = vars.op1d_var_exp = vars.op2n_var_exp = vars.op2d_var_exp = vars.result_powd = 1.0;
    memset(vars.result_pows, '\0', STR_MAXLEN);
}


void remove_pow1(char *s)
{
    char *p_x = strchr(s, 'x');
    if (
        *(p_x + 1) == '^' &&
        *(p_x + 2) == '1' &&
        !isdigit(*(p_x + 3))
    ) {
        *(p_x + 2) = '\0';
        *(p_x + 1) = '\0';
    }

}

void solve_alg(char *s)
{
    printf("\n\nStart of solve loop: %s\n", s);
    init_vars();
    find_bounds(s, &bounds.l, &bounds.r);
    parse_equation(s, bounds.l, bounds.r, eq.op1ns, eq.op1ds, &eq.oprtr, eq.op2ns, eq.op2ds);
    parse_var(eq.op1ns, &vars.op1n_var, &vars.op1n_var_exp);
    parse_var(eq.op1ds, &vars.op1d_var, &vars.op1d_var_exp);
    parse_var(eq.op2ns, &vars.op2n_var, &vars.op2n_var_exp);
    parse_var(eq.op2ds, &vars.op2d_var, &vars.op2d_var_exp);
    remove_vars(eq.op1ns);
    remove_vars(eq.op1ds);
    remove_vars(eq.op2ns);
    remove_vars(eq.op2ds);
    printf("\nBase digits after parsing vars:\n%s/%s %c %s/%s\n", eq.op1ns, eq.op1ds, eq.oprtr, eq.op2ns, eq.op2ds);


    calculate_var_exps(eq.oprtr, vars.op1n_var, vars.op1n_var_exp, vars.op2n_var, vars.op2n_var_exp, &vars.result_powd);

    convert_str_to_d(eq.op1ns, &eq.op1nd);
    convert_str_to_d(eq.op2ns, &eq.op2nd);
    calculate_result(eq.op1nd, eq.oprtr, eq.op2nd, &eq.resultnd);
    printf("Var result: %f\n", vars.result_powd);
    printf("Base result: %f\n", eq.resultnd);

    convert_d_to_str(eq.resultnd, eq.resultns);
    convert_d_to_str(vars.result_powd, vars.result_pows);
    remove_pow1(s);
    create_result_str(eq.resultns, vars.result_pows, "", eq.results);
    printf("Result string: %s\n", eq.results);

    insert_result(s, bounds.l, bounds.r, eq.results);
    printf("\n\nEnd of solve loop: %s\n\n", s);
}
