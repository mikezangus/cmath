void balance_chars(char c, short* scale, char char1, char char2)
{
    if (c == char1) {
        (*scale)++;
    } else if (c == char2) {
        (*scale)--;
    }
}
