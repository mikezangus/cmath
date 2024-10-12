#include <string.h>
#include "arithmetic.h"
#include "../../main.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"

EqAr eq;

void process_arithmetic(char* s, Bounds* b)
{
    while (verify(s)) {
    // for (int i = 0; i < 5; i++) {
        insert_parens(s);
        init_eq(&eq);
        if (!solve_arithmetic(s, &eq, b)) {
            return;
        }
    }
}
