#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "./arithmetic.h"

int process_arithmetic(char *s)
{
    insert_parens(s);
    while (verify(s)) {
        init_eq();
        solve(s);
    }
    return 1;
}
