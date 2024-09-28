#include "../../general/general.h"
#include "algebraic.h"
#include <stdio.h>

static void process_prec2(struct EquationAlg* eq)
{
    char exp_oprtr = '\0';
    switch (eq->oprtr) {
        case '*':
            exp_oprtr = '+';
            break;
        case '/':
            exp_oprtr = '-';
            break;
    }
    calculate_result(eq->op1_num_base_d, eq->oprtr, eq->op2_num_base_d, &eq->res_num_base_d);
    eq->res_num_var = eq->op1_num_var;
    calculate_result(eq->op1_num_exp_d, exp_oprtr, eq->op2_num_exp_d, &eq->res_num_exp_d);
}

static void process_prec3(struct EquationAlg* eq)
{
    calculate_result(eq->op1_num_base_d, eq->oprtr, eq->op2_num_base_d, &eq->res_num_base_d);
    eq->res_num_var = eq->op1_num_var;
    eq->res_num_exp_d = eq->op1_num_exp_d;
}

void calculate_vars(struct EquationAlg* eq)
{
    switch (eq->oprtr) {
        case '*':
            process_prec2(eq);
            return;
        case '/':
            process_prec2(eq);
            return;
        case '+':
            process_prec3(eq);
            return;
        case '-':
            process_prec3(eq);
            return;
    }
}
