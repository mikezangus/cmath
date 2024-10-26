#include "algebraic.h"
#include "../../general/general.h"
#include "../../utils/utils.h"
#include "../../main.h"
#include <stdio.h>

struct EqAlg eq_alg;

void process_algebraic(char* s)
{
    insert_mult(s);
    insert_mult1(s);
    insert_exp1(s);
    insert_eqzero(s);
    // insert_parens(s);
    printf("\nBefore rearrange:\n%s\n", s);
    rearrange(s);
    printf("Rearranged:\n%s\n", s);
    for (int i = 0; i < 3; i++) {
    // // while (verify(s)) {

        init_eq_alg(&eq_alg);
        // solve_alg(s, &eq_alg);
    }
    // printf("Done with solve loop, formatting\n");
    // remove_1(s);
    // remove_exp1(s);

    return;
}
