#include <string.h>
#include "arithmetic.h"
#include "../../main.h"

void init_eq(EqAr* eq)
{
    memset(eq->op1_num_s, '\0', STR_MAXLEN);
    memset(eq->op1_den_s, '\0', STR_MAXLEN);
    eq->oprtr = '\0';
    memset(eq->op2_num_s, '\0', STR_MAXLEN);
    memset(eq->op2_den_s, '\0', STR_MAXLEN);
}
