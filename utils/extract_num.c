#include <ctype.h>
#include <stdio.h>
#include "utils.h"

char* extract_num_fwd(char* dst, const char* start)
{
    const char* p = start;
    while (*p && is_num(p, start)) {
        *dst++ = *p++;
    }
    *dst = '\0';
    return (char*)(p - 1);
}

char* extract_num_bwd(char* dst, const char* start, const char* min)
{
    const char* p = start;
    for (; p > min && is_num(p, NULL); p--) {
        ;;
    }
    p = (p == min && (isdigit(*p) || *min == '-')) ? p : p + 1;
    for (const char* q = p; q <= start; q++) {
        *dst++ = *q;
    }
    *dst = '\0';
    return (char*)(p);
}
