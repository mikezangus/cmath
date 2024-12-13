#include <stdio.h>
#include "utils.h"

char* walk_num_bwd(const char* start, const char* src)
{
    const char* p = start;
    while (p > src && is_num(p, src)) {
        p--;
    }
    return (char*)(p == src && is_num(p, src) ? p : p + 1);
}

char* walk_num_fwd(const char* start)
{
    const char* p = start;
    while (*p && is_num(p, start)) {
        p++;
    }
    return (char*)(p - 1);
}
