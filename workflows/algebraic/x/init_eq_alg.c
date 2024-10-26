#include <string.h>
#include "algebraic.h"
#include "../../main.h"

void init_eq_alg(struct EqAlg* eq)
{
    eq->oprtr = '\0';


    memset(eq->op1_num_base_s, '\0', STR_MAXLEN);
    eq->op1_num_var = '\0';
    memset(eq->op1_num_exp_s, '\0', STR_MAXLEN);

    memset(eq->op1_den_base_s, '\0', STR_MAXLEN);
    eq->op1_den_var = '\0';
    memset(eq->op1_den_exp_s, '\0', STR_MAXLEN);


    memset(eq->op2_num_base_s, '\0', STR_MAXLEN);
    eq->op2_num_var = '\0';
    memset(eq->op2_num_exp_s, '\0', STR_MAXLEN);

    memset(eq->op2_den_base_s, '\0', STR_MAXLEN);
    eq->op2_den_var = '\0';
    memset(eq->op2_den_exp_s, '\0', STR_MAXLEN);


    eq->op1_num_base_d = 0.0;
    eq->op1_num_exp_d = 0.0;

    eq->op1_den_base_d = 0.0;
    eq->op1_den_exp_d = 0.0;


    eq->op2_num_base_d = 0.0;
    eq->op2_num_exp_d = 0.0;

    eq->op2_den_base_d = 0.0;
    eq->op2_den_exp_d = 0.0;


    eq->res_num_base_d = 0.0;
    eq->res_num_exp_d = 0.0;

    eq->res_num_var = '\0';

    memset(eq->res_num_base_s, '\0', STR_MAXLEN);
    memset(eq->res_num_exp_s, '\0', STR_MAXLEN);

    eq->res_den_base_d = 0.0;
    eq->res_den_exp_d = 0.0;

    eq->res_den_var = '\0';

    memset(eq->res_den_base_s, '\0', STR_MAXLEN);
    memset(eq->res_den_exp_s, '\0', STR_MAXLEN);


    memset(eq->result, '\0', STR_MAXLEN);
}
