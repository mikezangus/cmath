void balance_chars(char c, short* scale, char c_plus, char c_minus)
{
    if (c == c_plus) {
        (*scale)++;
    } else if (c == c_minus) {
        (*scale)--;
    }
}
