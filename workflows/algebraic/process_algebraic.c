#include <stdio.h>
#include "algebraic.h"
#include "../../general/general.h"
#include "../../main.h"
#include "../../utils/utils.h"

int i_eqsign;

int process_algebraic(void)
{


    printf("Input: %s\n", input);
    insert_mult();


    add_parens();
    // while(check_oprtr_exists() && check_parens_balanced()) {
    for (int i = 0; i < 3; i++) {
        printf("\n\n-----------------------------\nNEW LOOP: %s\n------------------------------\n", input);
        i_eqsign = 0;
        while (!(i_eqsign = find_eqsign())) {
            insert_eqzero();
        }
        isolate();
        find_eqsign();
        solve();
        remove_plus0();
        remove_x1();
        strip_parens();
        printf("Input: %s\n", input);
    }
    remove_x1();
    return 1;

}
