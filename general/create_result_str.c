void create_result_str(char *n, char *d, char *r)
{
    int j = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        r[j++] = n[i];
    }
    if (*d != '\0') {
        r[j++] = '/';
    }
    for (int i = 0; d[i] != '\0'; i++) {
        r[j++] = d[i];
    }
}
