#include <stdbool.h>
#include "../utils/utils.h"
#include "../workflows/algebraic/algebraic.h"

bool exponent_is_operable(char* op1, char* op2)
{
    return (!find_var(op1) && !find_var(op2));
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
