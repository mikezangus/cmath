#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../../utils/utils.h"

char* extract_num_fwd(char* dst, char* start)
{
    char* p = start;

    for (; *p && is_num(p, start); p++) {
        *dst++ = *p;
    }
    *dst = '\0';
    return p - 1;
}

char* extract_num_bwd(char* dst, char* start, char* min)
{
    char* p = start;
    for (; p > min && is_num(p, NULL); p--) {
    }
    p = (p == min && (isdigit(*p) || *min == '-')) ? p : p + 1;
    for (char* q = p; q <= start; q++) {
        *dst++ = *q;
    }
    *dst = '\0';
    return p;
}
