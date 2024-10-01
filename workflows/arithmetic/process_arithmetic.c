#include <string.h>
#include "./arithmetic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"

struct EqAr eq;

static void init(struct EqAr* eq)
{
    memset(eq->op1_num_s, '\0', STR_MAXLEN);
    memset(eq->op1_den_s, '\0', STR_MAXLEN);
    eq->oprtr = '\0';
    memset(eq->op2_num_s, '\0', STR_MAXLEN);
    memset(eq->op2_den_s, '\0', STR_MAXLEN);
}

void process_arithmetic(char* s)
{
    while (verify(s)) {
    // for (int i = 0; i < 2; i++) {
        insert_parens(s);
        init(&eq);
        solve(s, &eq);
    }
}
