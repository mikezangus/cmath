void balance_chars(char c, int* scale, char plus, char minus)
{
    if (c == plus) {
        (*scale)++;
    } else if (c == minus) {
        (*scale)--;
    }
}
