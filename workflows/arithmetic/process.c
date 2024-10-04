#include <string.h>
#include "arithmetic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"

EqAr eq;

void process_arithmetic(char* s)
{
    while (verify(s)) {
    // for (int i = 0; i < 3; i++) {
        insert_parens(s);
        init(&eq);
        if (!solve_arithmetic(s, &eq)) {
            return;
        }
    }
}
