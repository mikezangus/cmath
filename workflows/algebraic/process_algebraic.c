#include "algebraic.h"
#include "../../general/general.h"
#include "../../general/verifications/verifications.h"
#include "../../utils/utils.h"
#include "../../main.h"
#include <stdio.h>

void process_algebraic(char* s)
{
    insert_eqzero(s);
    insert_mult1(s);
    insert_exp1(s);
    insert_parens(s);
    print_str_indexes("\nInserted parens:", s);
    printf("\nBefore rearrange:\n%s\n", s);
    rearrange(s);
    printf("Rearranged:\n%s\n", s);
    for (int i = 0; i < 3; i++) {
    // // while (verify(s)) {

        // init_eq();
        // solve_alg(s);
    }
    // printf("Done with solve loop, formatting\n");
    // remove_1(s);
    // remove_exp1(s);

    return;
}
