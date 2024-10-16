void create_result_str(char* num, char* den, char* result)
{
    for (char* p = num; *p; p++) {
        *result++ = *p;
    }
    if (*den != '\0') {
        *result++ = '/';
        for (char* p = den; *p; p++) {
            *result++ = *p;
        }
    }
    *result = '\0';
}
