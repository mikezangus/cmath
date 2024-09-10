void collapse_str(char* s, int start, int end)
{
    for (int i = start; s[i] != '\0'; i++) {
        s[i] = s[i + end - start + 1];
    }
}
