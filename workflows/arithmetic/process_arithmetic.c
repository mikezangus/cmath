#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "./arithmetic.h"

void process_arithmetic(char* s)
{
    insert_parens(s);
    // while (verify(s)) {
    for (int i = 0; i < 2; i++) {
        init_eq();
        solve(s);
    }
}
