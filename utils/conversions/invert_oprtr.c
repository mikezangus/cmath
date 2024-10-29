char invert_oprtr(char oprtr)
{
    switch (oprtr) {
        case '*': return '/';
        case '/': return '*';
        case '+': return '-';
        case '-': return '+';
        default: return '\0';
    }
}