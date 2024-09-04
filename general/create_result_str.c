void create_result_str(char *n, char *d, char *r)
{
    int j = 0;
    for (char *p = n; *p != '\0'; p++) {
        r[j++] = *p;
    }
    if (*d != '\0') {
        r[j++] = '/';
    }
    for (char *p = d; *p != '\0'; p++) {
        r[j++] = *p;
    }
}
