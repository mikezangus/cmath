#include "../../main.h"
#include "../../general/general.h"

void solve_arithmetic(void)
{
    add_parens();
    while (check_oprtr_exists()) {
        solve();
    }
}
