void weigh_chars(char c, int *scale, char weight1, char weight2)
{
    if (c == weight1) {
        (*scale)++;
    } else if (c == weight2) {
        (*scale)--;
    }
}
