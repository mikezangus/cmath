#include <stdbool.h>

bool is_oprtr(char c)
{
    return is_prec1_oprtr(c) || is_prec2_oprtr(c) || is_prec3_oprtr(c);
}

bool is_prec1_oprtr(char c)
{
    return c == '^' || c == '√';
}

bool is_prec2_oprtr(char c)
{
    return c == '*' || c == '/';
}

bool is_prec3_oprtr(char c)
{
    return c == '+' || c == '-';
}

bool is_sub_oprtr(char c)
{
    return c == '-';
}
