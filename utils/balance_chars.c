void balance_chars(char c, short* scale, char plus, char minus)
{
    if (c == plus) {
        (*scale)++;
    } else if (c == minus) {
        (*scale)--;
    }
}
