void create_result_str(char* dst, char* n, char* d)
{
    for (char* p = n; *p; p++) {
        *dst++ = *p;
    }
    if (*d != '\0') {
        *dst++ = '/';
        for (char* p = d; *p; p++) {
            *dst++ = *p;
        }
    }
    *dst = '\0';
}
