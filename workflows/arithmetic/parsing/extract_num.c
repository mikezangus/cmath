#include <ctype.h>

char* extract_num_fwd(char* dst, char* start)
{
    char* p;
    for (p = start; *p && (isdigit(*p) || *p == '-'); p++) {
        *dst++ = *p;
    }
    *dst = '\0';
    return p - 1;
}

char* extract_num_bwd(char* dst, char* start, char* min)
{
    char* p;
    for (p = start; p >= min && (isdigit(*p) || *p == '-'); p--) {
        ;;
    }
    p = p == min && isdigit(*p) ? p : p + 1;
    for (char* q = p; q <= start; q++) {
        *dst++ = *q;
    }
    *dst = '\0';
    return p;
}
