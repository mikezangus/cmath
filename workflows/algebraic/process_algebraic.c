#include "algebraic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "../../utils/utils.h"
#include <stdio.h>

int process_algebraic(char *s)
{
    insert_mult(s);
    insert_eqzero(s);
    insert_parens(s);
    return 1;
}
