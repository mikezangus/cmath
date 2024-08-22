void expand_str(char *s, int start, int end)
{
    for (int i = start; i >= end; i--) {
        s[i] = s[i - 1];
    }
    s[end] = '~';
}
