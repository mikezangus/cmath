#include <stdbool.h>

bool is_operable(char *s, char *op, char *l_bound, char *r_bound)
{
    switch (*op) {
        case '^':
            if (*(op - 1) == 'x') {
                return 0;
            }
            return 1;
        case '/':
            if ((op + 1 == r_bound) && (*(op + 1) == '1')) {
                return 0;
            }
            bool var_in_numerator = false;
            bool var_in_denominator = false;
            for (char *p = l_bound; p <= r_bound; p++) {
                if (*p == 'x' && p < op) {
                    var_in_numerator = true;
                } else if (*p == 'x' && p > op) {
                    var_in_denominator = true;
                }
            }
            return var_in_numerator == var_in_denominator;
        default:
            return 1;
    }
}
