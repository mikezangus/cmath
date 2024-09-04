#include "algebraic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "../../utils/utils.h"
#include "../../main.h"
#include <stdio.h>

struct Variables vars;

int process_algebraic(char *s)
{
    sw.sw_var_exp = 0;
    // insert_mult(s);

    insert_eqzero(s);
    insert_1(s);
    // insert_parens(s);
    print_str("\nInserted parens:", s);
    for (int i = 0; i < 1; i++) {
    // while (verify(s)) {
        init_eq();
        init_vars();
        solve_alg(s);
    }
    printf("Done with solve loop, formatting\n");
    remove_1(s);
    remove_exp1(s);

    return 1;
}
