#include <string.h>
#include "algebraic.h"
#include "../../main.h"

void init_vars(void)
{
    vars.op1n_var = '\0';
    vars.op1n_exp = 1.0;
    vars.op1d_var = '\0';
    vars.op1d_exp = 1.0;

    vars.op2n_var = '\0';
    vars.op2n_exp = 1.0;
    vars.op2d_var = '\0';
    vars.op2d_exp = 1.0;

    memset(vars.result_varn, '\0', STR_MAXLEN);
    vars.result_expnd = 1.0;
    memset(vars.result_expns, '\0', STR_MAXLEN);

    memset(vars.result_vard, '\0', STR_MAXLEN);
    vars.result_expdd = 1.0;
    memset(vars.result_expds, '\0', STR_MAXLEN);

    memset(vars.resultns, '\0', STR_MAXLEN);
    memset(vars.resultds, '\0', STR_MAXLEN);
}
