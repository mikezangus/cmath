#include <stdbool.h>

bool is_divisible(long long op1, long long op2)
{
    return op2 != 0 && op1 % op2 == 0;
}

bool is_operable(long long op1, char oprtr, long long op2)
{
    switch (oprtr) {
        case '/': return is_divisible(op1, op2);
        default: return true;
    }
}
