#include "../../main.h"
#include "../../general/general.h"
#include "arithmetic.h"
#include <stdio.h>

int process_arithmetic(void)
{
    printf("Starting input: %s\n", input);
    if ((sw.division = check_division_exists())) {
        printf("\nDivision exists\n\n");
        add_parens_default();
        printf("\nAdded parens default: %s\n\n", input);
        insert_denoms();
        printf("\nInserted denoms: %s\n\n", input);
        add_parens_div();
        printf("\nAdded parens div: %s\n\n", input);
        find_i_parens();


    } else {
        printf("Division doesn't exist\n");
        add_parens_default();
    }

    // while (check_oprtr_exists()) {
    //     if (!check_parens_balanced()) {
    //         return 0;
    //     }
    //     solve();
    // }
    return 1;
}
