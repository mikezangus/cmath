#include <stdbool.h>

bool is_oprtr(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool is_prec1_oprtr(char c)
{
    return c == '^';
}

bool is_prec2_oprtr(char c)
{
    return c == '*' || c == '/';
}

bool is_prec3_oprtr(char c)
{
    return c == '+' || c == '-';
}
