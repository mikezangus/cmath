#include <stdbool.h>

bool is_oprtr(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
