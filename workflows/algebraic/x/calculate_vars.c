#include "../../general/general.h"
#include "algebraic.h"
#include <stdio.h>

static void process_prec2(struct EqAlg* eq_alg)
{
    char exp_oprtr = '\0';
    switch (eq_alg->oprtr) {
        case '*':
            exp_oprtr = '+';
            break;
        case '/':
            exp_oprtr = '-';
            break;
    }
    eq_alg->res_num_base_d = calculate_oprtn(eq_alg->op1_num_base_d,
                                              eq_alg->oprtr,
                                              eq_alg->op2_num_base_d);
    eq_alg->res_num_var = eq_alg->op1_num_var;
    eq_alg->res_num_exp_d = calculate_oprtn(eq_alg->op1_num_exp_d,
                                             exp_oprtr,
                                             eq_alg->op2_num_exp_d);
}

static void process_prec3(struct EqAlg* eq_alg)
{
    eq_alg->res_num_base_d = calculate_oprtn(eq_alg->op1_num_base_d,
                                              eq_alg->oprtr,
                                              eq_alg->op2_num_base_d);
    eq_alg->res_num_var = eq_alg->op1_num_var;
    eq_alg->res_num_exp_d = eq_alg->op1_num_exp_d;
}

void calculate_vars(struct EqAlg* eq_alg)
{
    switch (eq_alg->oprtr) {
        case '*':
            process_prec2(eq_alg);
            return;
        case '/':
            process_prec2(eq_alg);
            return;
        case '+':
            process_prec3(eq_alg);
            return;
        case '-':
            process_prec3(eq_alg);
            return;
    }
}
