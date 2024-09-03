#include "algebraic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "../../utils/utils.h"
#include "../../main.h"
#include <stdio.h>

struct Variables vars;

int process_algebraic(char *s)
{
    // insert_mult(s);

    insert_eqzero(s);
    insert_parens(s);
    print_str("\nInserted parens:", s);
    // for (int i = 0; i < 2; i++) {
    while (verify(s)) {
        init_eq();
        solve_alg(s);
    }


    return 1;
}
