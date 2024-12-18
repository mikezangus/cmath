void collapse_str(char* start, char* end)
{
    char* dst = start;
    char* src = end + 1;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = '\0';
}
