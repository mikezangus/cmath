#include <string.h>
#include "./arithmetic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"

struct EqAr eq_ar;

static void init(struct EqAr* eq_ar)
{
    memset(eq_ar->op1_num_s, '\0', STR_MAXLEN);
    memset(eq_ar->op1_den_s, '\0', STR_MAXLEN);
    eq_ar->oprtr = '\0';
    memset(eq_ar->op2_num_s, '\0', STR_MAXLEN);
    memset(eq_ar->op2_den_s, '\0', STR_MAXLEN);
}

void process_arithmetic(char* s)
{
    while (verify(s)) {
    // for (int i = 0; i < 2; i++) {
        insert_parens(s);
        init(&eq_ar);
        solve(s, &eq_ar);
    }
}
