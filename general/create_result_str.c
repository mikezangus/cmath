void create_result_str(char* dst, char* num, char* den)
{
    for (char* p = num; *p; p++) {
        *dst++ = *p;
    }
    if (*den != '\0') {
        *dst++ = '/';
        for (char* p = den; *p; p++) {
            *dst++ = *p;
        }
    }
    *dst = '\0';
}
