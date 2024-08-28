#include "../../general/general.h"

int process_arithmetic(void)
{
    add_parens();
    while (check_oprtr_exists()) {
        if (!check_parens_balanced()) {
            return 0;
        }
        solve();
    }
    return 1;
}
