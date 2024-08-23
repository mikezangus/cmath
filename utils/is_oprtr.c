int is_oprtr(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int is_prec1_oprtr(char c)
{
    return (c == '^');
}

int is_prec2_oprtr(char c)
{
    return (c == '*' || c == '/');
}
