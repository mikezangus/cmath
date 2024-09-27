#include <stdbool.h>
#include "../utils/utils.h"

bool exponent_is_operable(char* op1, char* op2)
{
    return (!str_contains_var(op1) && !str_contains_var(op2));
}

bool equation_is_operable(char* op1, char* oprtr, char* op2)
{
    switch(*oprtr) {
        case '^':
            return exponent_is_operable(op1, op2);
        default:
            return true;
    }
}
