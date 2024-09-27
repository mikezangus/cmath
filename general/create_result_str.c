void create_result_str(char* numerator, char* denominator, char* result)
{
    for (char* p = numerator; *p; p++) {
        *result++ = *p;
    }
    if (*denominator != '\0') {
        *result++ = '/';
        for (char* p = denominator; *p; p++) {
            *result++ = *p;
        }
    }
    *result = '\0';
}
